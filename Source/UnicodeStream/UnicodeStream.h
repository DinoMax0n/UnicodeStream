#pragma once 
#include "UnicodeStreamRealising.h"


namespace dm {
// For Windows
#ifdef _WIN32
    inline auto& cxxout = GetWinCxxout();
    inline auto& cxxin = GetWinCxxin();
#else
    
#endif
}