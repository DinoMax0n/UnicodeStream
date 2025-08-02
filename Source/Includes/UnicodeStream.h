#pragma once
#include <iostream>
#include <string>
using namespace std;



#ifdef _WIN32 // For Windows

class WinCxxout;

namespace dm
{
    inline WinCxxout& GetWinCxxout();
} 

class WinCxxout { //  cxxout for Windows (Declaring a class with a private constructor and an outward exit via the friend function)
    private:
        WinCxxout() = default;
        template <typename T> 
        void UWStream (const T& OutPutText) {
        cout << OutPutText; // Временно
    }

    public:
        friend WinCxxout& dm::GetWinCxxout();
        template <typename T>
        WinCxxout& operator<<(const T& OutPutText) { // For anyone types
            UWStream(OutPutText);
            return *this;
        }  
        WinCxxout& operator<<(std::wostream& (*manip)(std::wostream&)) {
            manip(std::wcout);
            return *this;
        }


};

namespace dm { // Designing namespace for Windows, ease of use
    inline WinCxxout& GetWinCxxout() {
        static WinCxxout instance;
        return instance;
    } 
}

#else // For Unix



#endif 
