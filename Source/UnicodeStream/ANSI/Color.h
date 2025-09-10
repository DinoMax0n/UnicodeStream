#pragma once

#include "../Includes.h"

namespace dm {
    namespace Color {
        std::string Red()    { return "\033[31m"; }
        std::string Orange() { return "\033[33m"; } // In ANSI8 dont have Orange 
        std::string Yellow() { return "\033[33m"; }
        std::string Green()  { return "\033[32m"; }
        std::string Cyan()   { return "\033[36m"; } 
        std::string Blue()   { return "\033[34m"; }
        std::string Violet() { return "\033[35m"; } 

        std::string AnsiRGB(int Red, int Green, int Blue) { return "\033[38;2;" + std::to_string(Red) + ";" + std::to_string(Green) + ";" + std::to_string(Blue) + "m";}
    }
}