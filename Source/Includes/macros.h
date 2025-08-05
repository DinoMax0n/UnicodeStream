#pragma once 
#include "UnicodeStream.h"


namespace dm {
// For Windows
#ifdef _WIN32
    inline auto& cxxout = GetWinCxxout();
#else
    
#endif
}