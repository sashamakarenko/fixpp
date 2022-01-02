#pragma once
#ifndef fix44_MESSAGES_H
#define fix44_MESSAGES_H

#include <fix44/Fields.h>

#include <vector>

namespace fix44
{

GetDepthMethod getTagDepthMethodByRawMsgType( raw_enum_t rawMsgType );

#include <fix44/Groups.hxx>

#include <fix44/Messages.hxx>

struct FixFormatStyle
{
    const char * messageBegin   ;
    const char * messageEnd     ;
    const char * indent         ;
    const char * groupFirstField;
    const char * fieldBegin     ;
    const char * fieldEnd       ;
    const char * headerTagNameStart;
    const char * headerTagNameStop ;
    const char * tagNameStart   ;
    const char * tagNameStop    ;
    const char * tagValueStart  ;
    const char * tagValueStop   ;
    const char * equal          ;
    const char * valueStart     ;
    const char * valueStop      ;
    const char * enumStart      ;
    const char * enumStop       ;
    const char * unknownStart   ;
    const char * unknownStop    ;
};

extern const FixFormatStyle defaultStyle;
extern const FixFormatStyle defaultVerticalStyle;
extern const FixFormatStyle ttyStyle;
extern const FixFormatStyle ttyRgbStyle;
extern const FixFormatStyle ttyRgbSingleLineStyle;

const GetDepthMethod autoIndentFields = (GetDepthMethod)(-1);

std::ostream & fixToHuman( const char * fix, offset_t & pos, std::ostream & os, const FixFormatStyle & style = defaultStyle, GetDepthMethod indentator = nullptr );

unsigned computeChecksum( const char * begin, const char * end );

unsigned parseMessageLength( const char * fix, unsigned & msgTypePos );

struct fixstr
{
    explicit fixstr( const char * fix, const FixFormatStyle & fstyle = defaultStyle, GetDepthMethod ind = autoIndentFields ): ptr(fix), style(fstyle), indentator{ind} {}
    const char * const ptr;
    const FixFormatStyle & style;
    const GetDepthMethod indentator;
};

const char * getEnumName( const char * fix, int valueOffset );

}

inline std::ostream & operator << ( std::ostream & os, const fix44::fixstr & msg )
{
    fix44::offset_t pos = 0;
    return fix44::fixToHuman( msg.ptr, pos, os, msg.style, msg.indentator );
}

#endif /* fix44_MESSAGES_H */

