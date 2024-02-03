__COPYRIGHT__

#include <vector>
#include <set>

#include <DSTINCDIR/Messages.h>

namespace DSTNAMESPACE
{

#include <DSTINCDIR/Messages.cxx>


ParserDispatcher::ParserDispatcher()
{
}

ParserDispatcher::~ParserDispatcher()
{
}

void ParserDispatcher::onUnknownMessage( raw_enum_t msgType )
{
}

bool ParserDispatcher::ignoreMessage( raw_enum_t msgType ) const
{
    return false;
}

void ParserDispatcher::unprocessedMessage( raw_enum_t msgType, MessageBase & msg )
{
}

std::set< raw_tag_t > headerRawTags =
{
#include <DSTINCDIR/HeaderRaw.cxx>
};

const FixFormatStyle defaultStyle =
{
    .messageBegin       = "",
    .messageEnd         = "",
    .indent             = "",
    .groupFirstField    = "",
    .fieldBegin         = "",
    .fieldEnd           = " ",
    .headerTagNameStart = "",
    .headerTagNameStop  = "",
    .tagNameStart       = "",
    .tagNameStop        = "",
    .tagValueStart      = "(",
    .tagValueStop       = ")",
    .equal              = "=",
    .valueStart         = "",
    .valueStop          = "",
    .enumStart          = "<",
    .enumStop           = ">",
    .unknownStart       = "",
    .unknownStop        = ""
};

const FixFormatStyle defaultVerticalStyle =
{
    .messageBegin       = "",
    .messageEnd         = "",
    .indent             = "  ",
    .groupFirstField    = " *",
    .fieldBegin         = " ",
    .fieldEnd           = "\n",
    .headerTagNameStart = "",
    .headerTagNameStop  = "",
    .tagNameStart       = "",
    .tagNameStop        = "",
    .tagValueStart      = "(",
    .tagValueStop       = ")",
    .equal              = "=",
    .valueStart         = "",
    .valueStop          = "",
    .enumStart          = "<",
    .enumStop           = ">",
    .unknownStart       = "",
    .unknownStop        = ""
};

const FixFormatStyle ttyStyle =
{
    .messageBegin       = "",
    .messageEnd         = "",
    .indent             = "  ",
    .groupFirstField    = " \u2022",
    .fieldBegin         = " ",
    .fieldEnd           = "\n",
    .headerTagNameStart = "",
    .headerTagNameStop  = "",
    .tagNameStart       = "\e[1m",
    .tagNameStop        = "\e[0m",
    .tagValueStart      = "(",
    .tagValueStop       = ")",
    .equal              = "=",
    .valueStart         = "",
    .valueStop          = "",
    .enumStart          = "<",
    .enumStop           = ">",
    .unknownStart       = "\e[31;1m",
    .unknownStop        = "\e[0m"
};

const FixFormatStyle ttyRgbStyle =
{
    .messageBegin       = "",
    .messageEnd         = "",
    .indent             = "  ",
    .groupFirstField    = " \u2022",
    .fieldBegin         = " ",
    .fieldEnd           = "\n",
    .headerTagNameStart = "\e[33m",
    .headerTagNameStop  = "\e[0m",
    .tagNameStart       = "\e[33;1m",
    .tagNameStop        = "\e[0m",
    .tagValueStart      = "(\e[37;1m",
    .tagValueStop       = "\e[0m)",
    .equal              = " = ",
    .valueStart         = "\e[34;1m",
    .valueStop          = "\e[0m",
    .enumStart          = " \e[32m",
    .enumStop           = "\e[0m",
    .unknownStart       = "\e[31;1m",
    .unknownStop        = "\e[0m"
};

const FixFormatStyle ttyRgbSingleLineStyle =
{
    .messageBegin       = "",
    .messageEnd         = "",
    .indent             = "",
    .groupFirstField    = "",
    .fieldBegin         = "",
    .fieldEnd           = "  ",
    .headerTagNameStart = "\e[33m",
    .headerTagNameStop  = "\e[0m",
    .tagNameStart       = "\e[33;1m",
    .tagNameStop        = "\e[0m",
    .tagValueStart      = "<\e[37;1m",
    .tagValueStop       = "\e[0m>",
    .equal              = "=",
    .valueStart         = "\e[34;1m",
    .valueStop          = "\e[0m",
    .enumStart          = "/\e[32m",
    .enumStop           = "\e[0m",
    .unknownStart       = "\e[31;1m",
    .unknownStop        = "\e[0m"
};

// no tag names
const FixFormatStyle ttyRgbRawStyle =
{
    .messageBegin       = "",
    .messageEnd         = "",
    .indent             = "",
    .groupFirstField    = "",
    .fieldBegin         = "",
    .fieldEnd           = " ",
    .headerTagNameStart = nullptr,
    .headerTagNameStop  = "\e[0m",
    .tagNameStart       = nullptr,
    .tagNameStop        = "\e[0m",
    .tagValueStart      = "\e[93;1m",
    .tagValueStop       = "\e[0m",
    .equal              = "=",
    .valueStart         = "\e[37;1m",
    .valueStop          = "\e[0m",
    .enumStart          = "/\e[92m",
    .enumStop           = "\e[0m",
    .unknownStart       = "\e[31;1m",
    .unknownStop        = "\e[0m"
};

// msgTypePos = offset of 35=
unsigned parseMessageLength( const char * fix, unsigned & msgTypePos )
{
    unsigned bodyLengthPos = msgTypePos = FixBeginStringValue.size() + 5; // 8=| + 9=|
    return parseUInt( fix + bodyLengthPos, ++msgTypePos );
}


unsigned computeChecksum( const char * begin, const char * end )
{
    unsigned sum = 0;
    while( begin < end )
    {
        sum += (unsigned)*begin++;
    }
    return sum & 0xff;
}

const char * getEnumName( const char * fix, int valueOffset )
{
    if( valueOffset < 0 )
    {
        return nullptr;
    }

    offset_t pos = (offset_t)valueOffset;
    while( pos > 0 and fix[pos-1] != FIXPP_SOH )
    {
        --pos;
    }

    const raw_tag_t tag = nextRawTag( fix+pos, pos );
    if( tag == 0 )
    {
        return nullptr;
    }

    auto eit = RAW_TO_ENUM.find( tag );
    if( eit == RAW_TO_ENUM.end() )
    {
        return nullptr;
    }
    const FieldEnumsBase * enums = eit->second;
    raw_enum_t rawEnum = toRawEnum( fix + valueOffset );
    const char * enumName = enums->getEnumNameByRaw( rawEnum );
    return enumName;
}

std::ostream & fixToHuman( const char * fix, offset_t & pos, std::ostream & os, const FixFormatStyle & style, GetDepthMethod indentator )
{
    os << style.messageBegin;

    while( fix[pos] )
    {
        offset_t prev = pos;
        const raw_tag_t tag = nextRawTag( fix+pos, pos );

        if( tag == 0 )
        {
            os << style.unknownStart << "[bad tag at " << pos << "]" << style.unknownStop << style.messageEnd;
            return os;
        }

        os << style.fieldBegin;

        auto it = RAW_TAG_TO_NAME.find( tag );
        const FieldEnumsBase * enums = nullptr;
        if( it != RAW_TAG_TO_NAME.end() )
        {
            if( headerRawTags.find( tag ) != headerRawTags.end() )
            {
                if( style.headerTagNameStart )
                {
                    os << style.headerTagNameStart << it->second << style.headerTagNameStop;
                }
            }
            else
            {
                if( indentator and indentator != autoIndentFields )
                {
                    FieldDepth fd = (*indentator)( tag );
                    if( fd.isFirstInGroup )
                    {
                        for( int d = 1; d < fd.depth; ++d ) os << style.indent;
                        os << style.groupFirstField;
                    }
                    else
                    {
                        for( int d = 0; d < fd.depth; ++d ) os << style.indent;
                    }
                }
                if( style.tagNameStart )
                {
                    os << style.tagNameStart << it->second << style.tagNameStop;
                }
            }

            auto eit = RAW_TO_ENUM.find( tag );
            if( eit != RAW_TO_ENUM.end() )
            {
                enums = eit->second;
            }
        }
        else
        {
            os << style.unknownStart << " ?" << style.unknownStop;
        }

        // tag
        os << style.tagValueStart;
        while( fix[prev] != '=' )
        {
            os << fix[prev++];
        }
        os << style.tagValueStop << style.equal << style.valueStart;

        raw_enum_t rawEnum = toRawEnum( fix + pos );

        // value as is
        while( fix[pos] and fix[pos] != FIXPP_SOH )
        {
            os << fix[pos++];
        }

        os << style.valueStop;

        // enum
        if( enums and style.enumStart )
        {
            const char * enumName = enums->getEnumNameByRaw( rawEnum );
            if( enumName )
            {
                os << style.enumStart << enumName << style.enumStop;
            }
            else
            {
                os << style.unknownStart << " UNKNOWN" << style.unknownStop;
            }

            if( tag == FieldMsgType::RAW and indentator == autoIndentFields )
            {
                indentator = getTagDepthMethodByRawMsgType( rawEnum );
            }

        }

        os << style.fieldEnd;
        os.flush();

        ++pos;
        if( tag == FieldCheckSum::RAW )
        {
            break;
        }

    }
    os << style.messageEnd;
    return os;
}

} // namespace DSTNAMESPACE

// gdb helper
extern "C" const char * fixppGetEnumName( const char * fix, int valueOffset )
{
    return DSTNAMESPACE::getEnumName( fix, valueOffset );
}
