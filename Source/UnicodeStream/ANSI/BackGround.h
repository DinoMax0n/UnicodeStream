#pragma once

namespace dm {
    namespace BackGround {
        std::string Red()    { return "\033[41m"; }
        std::string Orange() { return "\033[43m"; } // In ANSI8 dont have Orange
        std::string Yellow() { return "\033[43m"; }
        std::string Green()  { return "\033[42m"; }
        std::string Cyan()   { return "\033[46m"; }
        std::string Blue()   { return "\033[44m"; }
        std::string Violet() { return "\033[45m"; } 
    }
}