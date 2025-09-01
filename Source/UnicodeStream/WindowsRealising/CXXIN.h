#pragma once

#include "../Includes.h"
#include "Parser.h"

#ifdef _WIN32 // For Windows
#include <windows.h>
class WinCxxin;
inline WinCxxin& GetWinCxxin();

class WinCxxin { //  cxxin for Windows (Declaring a class with a private constructor and an outward exit via the friend function)
    private: 
        WinCxxin() = default;
        template <typename T>
        void UWRead(T& InputText) {
            HANDLE Hin = GetStdHandle(STD_INPUT_HANDLE);
            if (Hin == INVALID_HANDLE_VALUE || Hin == nullptr) {
                MessageBoxW(nullptr, L"Failed to get console handle", L"UnicodeStream" ,MB_OK | MB_ICONERROR);
                return;
            }
            std::vector<wchar_t> VectorReadsFromConsole;
            DWORD CharsRead = 0;
            while (true) {
                wchar_t BufferToReadConsole = 0; 
                if (!ReadConsoleW(Hin, &BufferToReadConsole, 1, &CharsRead, nullptr)) {
                    MessageBoxW(nullptr, L"Failed to get read symbols", L"UnicodeStream", MB_OK | MB_ICONERROR);
                }
                
                if (BufferToReadConsole == L'\r') {
                    ReadConsoleW(Hin, &BufferToReadConsole, 1, &CharsRead, nullptr);
                    break;
                }
                VectorReadsFromConsole.push_back(BufferToReadConsole);
            
            }
            // Output input text
            InputText = ParsedWinValue<T>(VectorReadsFromConsole);
        }

     public:
        friend WinCxxin& GetWinCxxin();
        template <typename T>
        WinCxxin& operator>>(T& InputText) {
            UWRead(InputText);
            return *this;
        }
    
};

inline WinCxxin& GetWinCxxin() {
    static WinCxxin instance;
    return instance;
} 
#endif