#pragma once

#include <iostream>
#include <iomanip>

#ifdef EXIT_ON_ERROR
#define CHECK_EXIT  if( not isGood ) exit(1);
#else
#define CHECK_EXIT 
#endif


#define CHECK( TITLE, EXPR, CONDITION ) {\
    auto res = EXPR;\
    bool isGood = res CONDITION;\
    const char * bg = isGood ? "\e[32;1m" : "\e[31;1m";\
    if( not isGood ) { std::cerr << "\e[33;1m" << __FILE__ << ":" << __LINE__ << ": \e[0m"; } \
    ( isGood ? std::cout : std::cerr ) << #TITLE << " : " << bg << std::boolalpha << res << "\e[0m" << std::endl;\
    CHECK_EXIT\
}
