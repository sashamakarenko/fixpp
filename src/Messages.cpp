#include <DSTINCDIR/Messages.h>

#include <DSTINCDIR/Debug.h>

#include <set>

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

std::set< raw_tag_t > headerFields =
{
#include <DSTINCDIR/Header.cxx>
};

const FixFormatStyle defaultStyle = 
{
    "",  //  messageBegin 
    "",  //  messageEnd   
    "",  //  indent
    "",  //  groupFirstField;
    "",  //  fieldBegin   
    " ", //  fieldEnd     
    "",  //  headerTagNameStart 
    "",  //  headerTagNameStop  
    "",  //  tagNameStart 
    "",  //  tagNameStop  
    "(", //  tagValueStart
    ")", //  tagValueStop 
    "=", //  equal        
    "",  //  valueStart   
    "",  //  valueStop    
    "<", //  enumStart    
    ">", //  enumStop     
    "",  //  unknownStart
    ""   //  unknownStop
};

const FixFormatStyle defaultVerticalStyle = 
{
    "",  //  messageBegin 
    "",  //  messageEnd   
    "  ",//  indent
    " *",//  groupFirstField;
    " ", //  fieldBegin   
    "\n",//  fieldEnd     
    "",  //  headerTagNameStart 
    "",  //  headerTagNameStop  
    "",  //  tagNameStart 
    "",  //  tagNameStop  
    "(", //  tagValueStart
    ")", //  tagValueStop 
    "=", //  equal        
    "",  //  valueStart   
    "",  //  valueStop    
    "<", //  enumStart    
    ">", //  enumStop     
    "",  //  unknownStart
    ""   //  unknownStop
};

const FixFormatStyle ttyStyle = 
{
    "",  //  messageBegin 
    "",  //  messageEnd   
    "  ",//  indent
    " \u2022",//  groupFirstField;
    " ", //  fieldBegin   
    "\n",//  fieldEnd     
    "",  //  headerTagNameStart 
    "",  //  headerTagNameStop  
    "\e[1m",  //  tagNameStart 
    "\e[0m",  //  tagNameStop  
    "(", //  tagValueStart
    ")", //  tagValueStop 
    "=", //  equal        
    "",  //  valueStart   
    "",  //  valueStop    
    "<", //  enumStart    
    ">",  //  enumStop     
    "\e[31;1m",  //  unknownStart
    "\e[0m"      //  unknownStop
};

const FixFormatStyle ttyRgbStyle =
{
    "",  //  messageBegin 
    "",  //  messageEnd   
    "  ",//  indent
    " \u2022",//  groupFirstField;
    " ", //  fieldBegin   
    "\n",//  fieldEnd     
    "\e[33m",  //  headerTagNameStart 
    "\e[0m",  //  headerTagNameStop  
    "\e[33;1m",  //  tagNameStart 
    "\e[0m",  //  tagNameStop  
    "(\e[37;1m", //  tagValueStart
    "\e[0m)", //  tagValueStop 
    " = ", //  equal        
    "\e[34;1m",  //  valueStart   
    "\e[0m",  //  valueStop    
    " \e[32m", //  enumStart    
    "\e[0m",  //  enumStop     
    "\e[31;1m",  //  unknownStart
    "\e[0m"      //  unknownStop
};

const FixFormatStyle ttyRgbSingleLineStyle =
{
    "",  //  messageBegin 
    "",  //  messageEnd   
    "",//  indent
    "",//  groupFirstField;
    "", //  fieldBegin   
    "  ",//  fieldEnd     
    "\e[33m",  //  headerTagNameStart 
    "\e[0m",  //  headerTagNameStop  
    "\e[33;1m",  //  tagNameStart 
    "\e[0m",  //  tagNameStop  
    "<\e[37;1m", //  tagValueStart
    "\e[0m>", //  tagValueStop 
    "=", //  equal        
    "\e[34;1m",  //  valueStart   
    "\e[0m",  //  valueStop    
    "/\e[32m", //  enumStart    
    "\e[0m",  //  enumStop     
    "\e[31;1m",  //  unknownStart
    "\e[0m"      //  unknownStop
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

    auto eit = rawToEnum.find( tag );
    if( eit == rawToEnum.end() )
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
        
        auto it = rawToTagName.find( tag );
        const FieldEnumsBase * enums = nullptr;
        if( it != rawToTagName.end() )
        {
            if( headerFields.find( tag ) != headerFields.end() )
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
            
            auto eit = rawToEnum.find( tag );
            if( eit != rawToEnum.end() )
            {
                enums = eit->second;
            }
        }
        else
        {
            os << style.unknownStart << "Unknown" << style.unknownStop;
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

}

// gdb helper
extern "C" const char * fixppGetEnumName( const char * fix, int valueOffset )
{
    return DSTNAMESPACE::getEnumName( fix, valueOffset );
}
