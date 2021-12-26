#pragma once

#include <iostream>
#include <iomanip>

#define CHECK( TITLE, EXPR, CONDITION ) {\
    auto res = EXPR;\
    const char * bg = ( res CONDITION ) ? "\e[32;1m" : "\e[31;1m";\
    std::cout << #TITLE << " : " << bg << std::boolalpha << res << "\e[0m" << std::endl;\
}
