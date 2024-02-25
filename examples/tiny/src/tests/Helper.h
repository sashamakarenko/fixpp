#pragma once

#ifdef UTEST_HELPER
#error could not include Helper.h twice
#endif

#define UTEST_HELPER

#include <iostream>
#include <iomanip>
#include <mutex>
#include <thread>
#include <chrono>
#include <array>

using namespace std::literals::string_literals;

inline void sleep_millis( unsigned millis )
{
    std::this_thread::sleep_for( std::chrono::milliseconds( millis ) );
}

#ifdef EXIT_ON_ERROR
#define CHECK_EXIT  if( not check_isGood_ ) { sleep_millis( 100 ); exit(1); }
#else
#define CHECK_EXIT
#endif


std::mutex utestsLogMutex;

struct LogGuard
{
    LogGuard(): lock( utestsLogMutex )
    {
    }
    std::unique_lock<std::mutex> lock;
};

const char * TTY_RESET = "\e[0m";

#define CHECK_PREFIXED( PREFIX, TITLE, EXPR, CONDITION ) {\
    auto check_res_ = EXPR;\
    bool check_isGood_ = check_res_ CONDITION;\
    {\
        LogGuard g__;\
        if( not check_isGood_ ) { std::cerr << "\e[33;1m" << __FILE__ << ":" << __LINE__ << ": " << TTY_RESET; } \
        ( check_isGood_ ? std::cout : std::cerr ) << PREFIX << #TITLE << " : " << ( check_isGood_ ? "\e[34m<\e[32;1m" : "\e[35m<\e[31;1m" ) << std::boolalpha << check_res_ << ( check_isGood_ ? "\e[34m>" : "\e[35m>" ) << TTY_RESET << std::endl;\
    }\
    CHECK_EXIT\
}

const std::array< const char *, 4 > TTY_FGS =
{
    "\e[94m",
    "\e[95m",
    "\e[96m",
    "\e[97m"
};

#define CHECK( TITLE, EXPR, CONDITION )         CHECK_PREFIXED(         "", TITLE, EXPR, CONDITION )
#define CHECK_BLUE( TITLE, EXPR, CONDITION )    CHECK_PREFIXED( TTY_FGS[0], TITLE, EXPR, CONDITION )
#define CHECK_MAGENTA( TITLE, EXPR, CONDITION ) CHECK_PREFIXED( TTY_FGS[1], TITLE, EXPR, CONDITION )
#define CHECK_CYAN( TITLE, EXPR, CONDITION )    CHECK_PREFIXED( TTY_FGS[2], TITLE, EXPR, CONDITION )
#define CHECK_WHITE( TITLE, EXPR, CONDITION )   CHECK_PREFIXED( TTY_FGS[3], TITLE, EXPR, CONDITION )

#define STRINGIFY_(X) #X
#define STRINGIFY(X) STRINGIFY_(X)
