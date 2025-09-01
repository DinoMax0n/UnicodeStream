#pragma once 

namespace dm {
    namespace Style {
        std::string Bold()       { return "\033[1m"; }
        std::string Dim()        { return "\033[2m"; }
        std::string Italic()     { return "\033[3m"; } // If it dont work koment him and dont used
        std::string Underline()  { return "\033[4m"; }
        std::string Blink()      { return "\033[5m"; } // If it dont work koment him and dont used
        std::string Reverse()    { return "\033[7m"; }
        std::string Hidden()     { return "\033[8m"; }
        std::string Strike()     { return "\033[9m"; }
}
}