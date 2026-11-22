#include <tiny/MessageSelect.h>
#include "FixSamples.h"

#include <utests/TrivialHelper.h>

using namespace tiny;
using namespace tiny::field;
using namespace tiny::message;

int main( int args, const char ** argv )
{
    Header header;
    offset_t pos;
    size_t msglen;
    const char * fix;

    HIGHLIGHT( ExecutionReport select );
    fix = EXAMPLE_LARGE_EXEC_REPORT;
    msglen = strlen( fix );
    ExecutionReport er;
    header.reset();
    pos = header.select<SenderCompID>( fix, msglen );
    CHECK_EQ( sender comp id, header.getSenderCompIDView(), "foo" );
    pos += er.select<Price,OrderQty,NoLegs,LegSymbol,NoNestedPartyIDs,NestedPartyID>( fix + pos, msglen - pos );
    CHECK_EQ( exec report price, er.getPrice(), 15.001 );
    CHECK_EQ( exec report no legs, er.getNoLegs(), 2 );
    auto & leg = er.getGroupLegs( 0 );
    CHECK_EQ( exec report leg symbol, leg.getLegSymbolView(), "SYM1" );
    CHECK_EQ( exec report leg qty set, leg.isSetLegQty(), false );
    auto & partyId = leg.getGroupNestedPartyIDs( 0 );
    CHECK_EQ( exec report leg party id, partyId.getNestedPartyIDView(), "PARTY1" );

    HIGHLIGHT( ExecutionReport select and stop on NoLegs );
    header.reset();
    er.reset();
    pos = header.skip( fix, msglen );
    pos += er.select<Price,OrderQty,NoLegs,StopOn<NoLegs>>( fix + pos, msglen - pos );
    CHECK_EQ( exec report price, er.getPrice(), 15.001 );
    CHECK_EQ( exec report no legs, er.getNoLegs(), 2 );

    HIGHLIGHT( ExecutionReport select all and stop on LeavesQty );
    header.reset();
    er.reset();
    pos = header.skip( fix, msglen );
    pos += er.select<AllFields,StopOn<LeavesQty>>( fix + pos, msglen - pos );
    auto [ price, symbol, leavesQty ] = er.getFields<Price,Symbol,LeavesQty>();
    CHECK_EQ( exec report price, price, 15.001 );
    CHECK_EQ( exec report symbol, symbol, "XYZ" );
    CHECK_EQ( exec report leaves qty, leavesQty, 15 );
    return 0;
}
