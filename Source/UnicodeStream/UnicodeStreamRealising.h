
#pragma once

#include "UnicodeStreamIncludes.h"
#include "UnicodeStreamFunctionsConvertions.h"

#ifdef _WIN32 // For Windows
#include <windows.h>
class WinCxxout;
inline WinCxxout& GetWinCxxout();

class WinCxxout { //  cxxout for Windows (Declaring a class with a private constructor and an outward exit via the friend function)
    private:
        WinCxxout() = default;
        template <typename T> 
        void UWStream (const T& OutPutText) {
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
            UWStream(OutPutText);
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

class WinCxxin;
inline WinCxxin& GetWinCxxin();

class WinCxxin {
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
            InputText = ParsedValue<T>(VectorReadsFromConsole);
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

#else // For Unix



#endif 
