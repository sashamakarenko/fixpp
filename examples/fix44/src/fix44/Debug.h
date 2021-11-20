#pragma once

#define DEBUG_PARSERx

#ifdef DEBUG_PARSER
#define PRINT_FIELD(NAME) std::cout << Field##NAME::tagName() << "(" << Field##NAME::tagKey() << ") = " << sohstr( fix+pos ) << std::endl;
#define PRINT_UNKNOWN std::cout << "- unknown " << tag << " in " << getMessageName() << ":" << pos << " " << sohstr( fix+prev ) << std::endl;
#else
#define PRINT_FIELD(NAME)
#define PRINT_UNKNOWN
#endif

