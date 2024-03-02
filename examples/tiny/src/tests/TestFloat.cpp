#include "Helper.h"
#include <tiny/FixFloat.h>
#include <set>

using namespace tiny;

int main( int args, const char ** argv )
{

    Float f1 = 1.2345;
    Float f2 = 2;
    CHECK( f1 != f2, f1, != f2 )

    Float F1 = 1.2345;
    CHECK( F1 == f1, F1, == f1 )

    Float F2( -0.2345, 8 );
    CHECK( F2 < F1, F2, < F1 )

    F1 = -0.2345;
    CHECK( F2 == F1, F2, == F1 )
    CHECK( F2 < 0, F2, < 0 )
    CHECK( F2 < 0.1, F2, < 0.1 )

    CHECK( F2 < 0UL, F2, < 0UL )
    CHECK( F2 < 0.1f, F2, < 0.1f )

    Float F3( -2345, 4 );
    CHECK( F3 == F1, F3, == F1 )
    CHECK( F3 == F2, F3, == F2 )
    CHECK( F3._int == -2345, F3.getUnderlyingInteger(), == -2345 )

    char buf[ 20 ];
    f1 = 0;
    f1.format( buf );
    CHECK( format 0, f1.toString(), == buf )

    f1 = "0.000"_ff;
    f1.format( buf );
    CHECK( format 0.000, f1.toString(), == buf )

    f1 = "123"_ff;
    f1.format( buf );
    CHECK( format 123, f1.toString(), == buf )

    f1 = "400.000123"_ff;
    f1.format( buf );
    CHECK( format 400.000123, f1.toString(), == buf )

    f1 = "-0.10003"_ff;
    f1.format( buf );
    CHECK( format -0.10003, f1.toString(), == buf )

    f1 = "-123456789.10003"_ff;
    f1.format( buf );
    CHECK( format -123456789.10003, f1.toString(), == buf )

    CHECK( Float( 1 5 ) == 0.00001, Float(1,5), == 0.00001_ff )
    CHECK( Float( 1 5 ) == "0.00001", Float(1,5), == "0.00001"_ff )
    CHECK( Float( -1012345678 8 ) == "-10.12345678", Float(-1012345678,8), == "-10.12345678"_ff )
    CHECK( Float( -1012345678 8 ).toString() == "-10.12345678", Float(-1012345678,8).toString(), == "-10.12345678" )
    CHECK( "100000000000000", Float( 100000000000000 ), == "100000000000000"_ff )
    CHECK( "100000000000000.", Float( 100000000000000 ), == "100000000000000."_ff )
    Float overflow = "1000000000000000.000000"_ff;
    CHECK( "1000000000000000.000000" overflow, overflow.isOverflow(), == true )


    CHECK( Float( 1 7 ) == "000.0000001", Float(1,7), == "000.0000001"_ff )
    CHECK( Float( 23 5 ) == "0.00023000", Float(23,5), == "0.00023000"_ff )
    CHECK( Float( 23000 8 ) == "0.00023000", Float(23000,8), == "0.00023000"_ff )

    CHECK( 0:0 + 0:0, Float(0,0) + Float(0,0), == FLOAT_0 )
    CHECK( 0:5 + 0:8, Float(0,5) + Float(0,8), == FLOAT_0 )
    CHECK( 0:0 + 1:0, Float(0,0) + Float(1,0), == FLOAT_1 )
    CHECK( 100:2 == 1, Float(100,2), == FLOAT_1 )
    CHECK( 0:0 + 100:2, Float(0,0) + Float(100,2), == FLOAT_1 )
    CHECK( 10000:4 + 100:2, Float(10000,4) + Float(100,2), == FLOAT_2 )
    CHECK( 10002:4 + 10003:4, Float(10002,4) + Float(10003,4), == "2.0005"_ff )
    CHECK( 10002:4 + -10003:4, Float(10002,4) + Float(-10003,4), == "-0.0001"_ff )
    overflow = Float(9'000'000'000'000'000'000) + Float(9'000'000'000'000'000'000);
    CHECK( sum overflow, overflow.isOverflow(), == true )
    CHECK( sum 99, Float(9'000'000'000'000'000'000, 18 ) + Float(9'000'000'000'000'000'000, 17), == Float(99) );
    CHECK( sum -99, Float(-9'000'000'000'000'000'000, 18 ) + Float(-9'000'000'000'000'000'000, 17), == Float(-99) );
    CHECK( sum 81, Float(-9'000'000'000'000'000'000, 18 ) + Float(9'000'000'000'000'000'000, 17), == Float(81) );

    CHECK( 0:0 - 0:0, Float(0,0) - Float(0,0), == FLOAT_0 )
    CHECK( 0:5 - 0:8, Float(0,5) - Float(0,8), == FLOAT_0 )
    CHECK( 0:0 - 1:0, Float(0,0) - Float(1,0), == Float(-1,0) )
    CHECK( 9999999:6 -99999990:7, Float(9'999999,6) - Float(9'9999990,7), == FLOAT_0 )

    CHECK( 0:0 * 0:0, Float(0,0) * Float(0,0), == FLOAT_0 )
    CHECK( 0:5 * 0:8, Float(0,5) * Float(0,8), == FLOAT_0 )
    CHECK( 0:0 * 1:0, Float(0,0) * Float(1,0), == FLOAT_0 )
    CHECK( 10:0 * 1:0, Float(10,0) * Float(1,0), == FLOAT_10 )
    CHECK( 12'000'000:6 * 2000'000'000:9, Float(12'000'000,6) * Float(2000'000'000,9), == Float(24) )
    Float res = Float(3'000'000'000) * Float(2'000'000'000);
    CHECK( 3*10^6 * 2*10^6, res, == Float(6'000'000'000'000'000'000) )
    CHECK( 10'000'000'001 * 2, Float( 10'000'000'001 ) * Float( 2 ), == Float(20'000'000'002) )
    CHECK( 10'000'000'001 * 20002, Float( 10'000'000'001 ) * Float( 20002 ), == Float(20002'00000'20002) )
    overflow =  Float( 10'000'000'000 ) * Float( 10'000'000'000 );
    CHECK( 10^10 * 10^10 overflow, overflow.isOverflow(), == true )

    CHECK( 0 / 0 is NaN, ( Float(0) / Float(0) ).isNotANumber(), == true )
    CHECK( 1 / 0 is inf, ( Float(1) / Float(0) ).isInfinite(), == true )
    CHECK( 1 / 3, Float(1) / Float(3), == Float(333'333'333'333'333, Float::MAX_DIGITS) )
    CHECK( 2 / 3, Float(2) / Float(3), == Float(666'666'666'666'666, Float::MAX_DIGITS) )
    CHECK( 3 / 3, Float(3) / Float(3), == FLOAT_1 )
    CHECK( 5 / 3, Float(5) / Float(3), == Float(1'666'666'666'666'66, Float::MAX_DIGITS - 1 ) )
    CHECK( 50/ 3, Float(50)/ Float(3), == Float(1'666'666'666'666'66, Float::MAX_DIGITS - 2 ) )
    CHECK( 12'000'000:6 / 2000'000'000:9, Float(12'000'000,6) / Float(2000'000'000,9), == Float(6) )
    CHECK( 0:0 / 1:0, Float(0,0) / Float(1,0), == FLOAT_0 )
    CHECK( 10:0 / 2:0, Float(10,0) / Float(2,0), == Float(5) )
    CHECK( 10:0 / 25:1, Float(10,0) / Float(25,1), == Float(4) )
    CHECK( 1'2345:4 / 5:0, Float(1'2345,4) / Float(5), == Float(2469,4) )
    CHECK( 1'2345:10 / 5:0, Float(1'2345,10) / Float(5), == Float(2469,10) )
    CHECK( 10:0 / -25:1, Float(10,0) / Float(-25,1), == Float(-4) )
    CHECK( -10:0 / 25:1, Float(-10,0) / Float(25,1), == Float(-4) )
    CHECK( -10:0 / -25:1, Float(-10,0) / Float(-25,1), == Float(4) )

    CHECK( 1 / 0.1, Float(1)  / Float(1,1), == Float(10) )
    CHECK( 1 / 0.01, Float(1) / Float(1,2), == Float(100) )
    CHECK( 1 / 0.00001, Float(1) / Float(1,5), == Float(100000) )
    CHECK( 1 / 0.000'000'000'1, Float(1) / Float(1,10), == Float(1'000'000'000'0) )
    CHECK( 1 / 0.000'000'000'001, Float(1) / Float(1,12), == Float(1'000'000'000'000) )
    CHECK( 1 / 0.000'000'000'000'1, Float(1) / Float(1,13), == Float(1'000'000'000'000'0) )
    CHECK( 1 / 0.000'000'000'000'01, Float(1) / Float(1,14), == Float(1'000'000'000'000'00) )
    CHECK( 5 / 0.000'000'000'000'02, Float(5) / Float(2,14), == Float(2'500'000'000'000'00) )

    CHECK( 30'000'000'000 / 6'000, Float(30'000'000'000) / Float(6'000), == Float(5'000'000) )

    CHECK( 12345 / 0.12345, Float(12345) / Float(12345,5), == Float(100000) )
    CHECK( 12345 / 1.2345, Float(12345) / Float(12345,4), == Float(10000) )
    CHECK( 12345 / 1234.5, Float(12345) / Float(12345,1), == Float(10) )
    CHECK( 12345 / 123450, Float(12345) / Float(123450), == Float(1,1) )
    CHECK( 1.2345 / 123450, Float(12345,4) / Float(123450), == Float(1,5) )
    CHECK( 20002 / 10.001, Float(20002) / Float(10001,3), == Float(2000) )

    double reals[] =
    {
        -1046418201.7283,
        -946418201.317283,
        -82028132.63440410,
        -7323782.817383123,
        -54219.08118,
        -4394.123,
        -312.539445052,
        -24.32,
        -3.000001,
        -0.643493,
        -0.0289258520287,
        -0.0000000168476,
        -0.00000005,
         0.0000000123,
         0.000000006,
         0.003500003232,
         0.7632992,
         8.421000001,
         19.,
         391.01732943403,
         4927.217890,
         52492.00000001,
         601134.20082,
         89005340.32,
         931732920.132,
         1032100002
    };
    const unsigned nbOfReals = sizeof(reals)/sizeof(double);
    unsigned combinations = 0;
    unsigned successes    = 0;

    for( unsigned aprecision = 2; aprecision < 9; ++aprecision )
    {
    for( unsigned bprecision = 2; bprecision < 9; ++bprecision )
    {
    double accuracy = div10Pow[ std::min( aprecision, bprecision) ];
    for( unsigned i = 0; i < nbOfReals; ++i )
    {
        double a = std::round(reals[i] * uintPow10[aprecision]) / uintPow10[aprecision];
        const Float fa( a, aprecision );
        if( not fa.isCloseTo( a, accuracy ) )
        {
            CHECK( fa != a, fa.toString(), == "" )
        }

        for( unsigned j = 0; j < nbOfReals; ++j )
        {
            double b = std::round(reals[j] * uintPow10[bprecision]) / uintPow10[bprecision];
            const Float fb( b, bprecision );
            if( not fb.isCloseTo( b, accuracy ) )
            {
                CHECK( fb != b, fb.toString(), == "" )
            }

            // +
            Float fab;
            double ab;
            for( int op = 0; op < 8; ++op )
            {
                ++combinations;
                const char * opname = "?";
                switch( op )
                {
                    case 0:
                        ab = a + b;
                        fab = fa + fb;
                        opname = "a+b";
                        break;
                    case 1:
                        ab = b + a;
                        fab = fb + fa;
                        opname = "b+a";
                        break;
                    case 2:
                        ab = a - b;
                        fab = fa - fb;
                        opname = "a-b";
                        break;
                    case 3:
                        ab = b - a;
                        fab = fb - fa;
                        opname = "b-a";
                        break;
                    case 4:
                        ab = a * b;
                        fab = fa * fb;
                        opname = "a*b";
                        break;
                    case 5:
                        ab = b * a;
                        fab = fb * fa;
                        opname = "b*a";
                        break;
                    case 6:
                        ab = a / b;
                        fab = fa / fb;
                        opname = "a/b";
                        break;
                    case 7:
                        ab = b / a;
                        fab = fb / fa;
                        opname = "b/a";
                        break;
                }

                if( fab.isInfinite() and
                    std::isinf( ab ) )
                {
                    continue;
                }

                if( fab.isOverflow() )
                {
                    continue;
                }

                if( ( std::abs( fab.asDouble() - ab ) > accuracy ) and not fab.isCloseTo( ab, accuracy ) )
                {
                    // Float dab = fa / fb;
                    CHECK( op, op, >= 0 )
                    CHECK( op name, opname, != nullptr )
                    CHECK( accuracy, accuracy, > 0 )
                    CHECK( a, a, != 9.99999999999 )
                    CHECK( a precision, aprecision, != 0 )
                    CHECK( b, b, != 9.99999999999 )
                    CHECK( b precision, bprecision, != 0 )
                    CHECK( a op b, ab, != 9.99999999999 )
                    CHECK( fa, fa.toString(), != "" )
                    CHECK( fb, fb.toString(), != "" )
                    CHECK( fa op fb, fab.toString(), != "" )
                    CHECK( diff, fab.asDouble() - ab, == 0 )
                }
                ++successes;
            }

        }
    }
    }
    }
    CHECK( combinations, combinations, > 0 )
    CHECK( successes, successes, > 0 )

    CHECK( "10"_ff + 10, "10"_ff + 10, == "20"_ff )
    CHECK( "10"_ff + 1.2345, "10"_ff + 1.2345, == "11.2345"_ff )
    CHECK( 10 + "10"_ff, 10 + "10"_ff, == "20"_ff )
    CHECK( 1.2345 + "10"_ff, 1.2345 + "10"_ff, == "11.2345"_ff )

    return 0;
}
