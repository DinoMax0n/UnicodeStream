/*
INCLUDEME!!!!
*/
#pragma once 

#include "ANSI/Ansi.h"

namespace dm {
// For Windows
#ifdef _WIN32
    #include "WindowsRealising/CXXIN.h"
    #include "WindowsRealising/CXXOUT.h"
    inline auto& cxxout = GetWinCxxout();
    inline auto& cxxin = GetWinCxxin();
#else
    #include "PosixRealising/CXXIN.h"
    #include "PosixRealising/CXXOUT.h"
    inline auto& cxxout = GetUnixCxxout();
    inline auto& cxxin = GetUnixCxxin();
#endif
}