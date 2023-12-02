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

#ifdef EXIT_ON_ERROR
#define CHECK_EXIT  if( not isGood ) exit(1);
#else
#define CHECK_EXIT
#endif

inline void sleep_millis( unsigned millis )
{
    std::this_thread::sleep_for( std::chrono::milliseconds( millis ) );
}

std::mutex utestsLogMutex;

struct LogGuard
{
    LogGuard(): lock( utestsLogMutex )
    {
    }
    std::unique_lock<std::mutex> lock;
};

#define CHECK( TITLE, EXPR, CONDITION ) {\
    LogGuard g__;\
    auto res = EXPR;\
    bool isGood = res CONDITION;\
    const char * bg = isGood ? "\e[32;1m" : "\e[31;1m";\
    if( not isGood ) { std::cerr << "\e[33;1m" << __FILE__ << ":" << __LINE__ << ": \e[0m"; } \
    ( isGood ? std::cout : std::cerr ) << #TITLE << " : " << bg << std::boolalpha << res << "\e[0m" << std::endl;\
    CHECK_EXIT\
}
