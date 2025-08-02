#pragma once 
#include "UnicodeStream.h"

// For Windows
#ifdef _WIN32
namespace dm {
    #define cxxout dm::GetWinCxxout() //cxxout
//For Unix
#else

#endif
}