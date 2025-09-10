/*
This file was created to quickly combine all formatting into 1 file 
(maybe you only need formatting)*/

#include <string>
#include "Color.h"
#include "BackGround.h"
#include "Style.h"

namespace dm {
    namespace Reset {
        std::string All() { return "\033[0m"; }
        std::string Color()      { return "\033[39m"; } 
        std::string Background() { return "\033[49m"; }
        std::string Styles() {
        return "\033[22m"  // Bold, Dim
               "\033[23m"  // Italic
               "\033[24m"  // Underline
               "\033[25m"  // Blink
               "\033[27m"  // Reverse
               "\033[28m"  // Hidden
               "\033[29m"; // Strike
        }
    }
}