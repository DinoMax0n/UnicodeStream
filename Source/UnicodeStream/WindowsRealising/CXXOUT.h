#pragma once

#include "../Includes.h"

#ifdef _WIN32 // For Windows
#include <windows.h>

void EnableANSIWindows() { // For Support ANSI
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE) return;

    DWORD dwMode = 0;
    if (!GetConsoleMode(hOut, &dwMode)) return;

    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
}

class WinCxxout;
inline WinCxxout& GetWinCxxout();

class WinCxxout { //  cxxout for Windows (Declaring a class with a private constructor and an outward exit via the friend function)
    private:
        WinCxxout() = default;
        template <typename T> 
        void UWWrite (const T& OutPutText) {
            EnableANSIWindows();
            HANDLE HOut = GetStdHandle(STD_OUTPUT_HANDLE);
            if (HOut == INVALID_HANDLE_VALUE || HOut == nullptr) {
                MessageBoxW(nullptr, L"Failed to get console handle", L"UnicodeStream" ,MB_OK | MB_ICONERROR);
            }
            std::wstring wstr = FormatToWstring(OutPutText);
            std::vector<wchar_t> OutPutVectorWstring(wstr.begin(), wstr.end());
            DWORD CharsToWrite = static_cast<DWORD>(wstr.size());
            DWORD CharsWritten = 0;
            BOOL SeccessWrite = WriteConsoleW(HOut, OutPutVectorWstring.data(), CharsToWrite, &CharsWritten, NULL );
            if (SeccessWrite != true) {
                MessageBoxW(nullptr, L"Failed to output words to console", L"UnicodeStream" ,MB_OK | MB_ICONERROR);
            }
            else if (CharsWritten < CharsToWrite) {
                MessageBoxW(nullptr, L"More characters than expected were output to the console", L"UnicodeStream" ,MB_OK | MB_ICONWARNING);
            }
        }

    public:
        friend WinCxxout& GetWinCxxout();
        template <typename T>
        WinCxxout& operator<<(const T& OutPutText) { // For anyone types
            UWWrite(OutPutText);
            return *this;
        }  
        WinCxxout& operator<<(std::wostream& (*manip)(std::wostream&)) {
            manip(std::wcout);
            return *this;
        }


};

inline WinCxxout& GetWinCxxout() {
    static WinCxxout instance;
    return instance;
} 
#endif