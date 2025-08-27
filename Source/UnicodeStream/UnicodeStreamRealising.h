
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
        void UWWrite (const T& OutPutText) {
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

#else // For Unix Like OS
#include <unistd.h>

class UnixCxxout;
inline UnixCxxout& GetUnixCxxout();

class UnixCxxout {
    private:
        UnixCxxout() = default;
        void UUWrite(const std::vector<char>& OutPutText) {
            ssize_t SeccessWrite = write(STDOUT_FILENO, OutPutText.data(), OutPutText.size());
            if (SeccessWrite == -1) {
                std::cerr << "Failed to output words to console";
            }
        }
    public:
        friend UnixCxxout& GetUnixCxxout();
        template <typename T>
        UnixCxxout& operator<<(const T& OutPutText) { // For anyone types
            auto buffer = FormatToString(OutPutText);
            UUWrite(buffer);
            return *this;
        }  
        UnixCxxout& operator<<(std::wostream& (*manip)(std::wostream&)) {
            manip(std::wcout);
            return *this;
        }
};

inline UnixCxxin& GetUnixCxxin() {
    static UnixCxxin instance;
    return instance;
} 

class UnixCxxin;
inline UnixCxxin& GetUnixCxxin();

class UnixCxxin {
    private:
    UnixCxxint() = default;
    template <typename T>
    void UURead (T &InputText) {
        std::vector<char> ArrayInputText;
        while (true) {
            char buffer = '\0';
            ssize_t Result = read(STDIN_FILENO, &buffer, 1);

            if (Result <= 0) {
                break;
            }

            if (buffer == '\r') {
                ssize_t ResultTakeAway = read(STDIN_FILENO, &buffer, 1);
                if (ResultTakeAway > 0 && buffer == '\n') {}
                else {
                    std::cerr << "Error, after \r dont find \n (Errors are possible)";
                }
                break;
            } 
            else {
                ArrayInputText.push_back(buffer);
            }
        }
        InputText ParsedUnixValue<T>(ArrayInputText);
    }
    public:
    friend inline UnixCxxin& GetUnixCxxin();
    template <typename T>
    UnixCxxin& operator>>(T& Value) {
        UURead(Value); 
        return *this;
    }
};


#endif 
