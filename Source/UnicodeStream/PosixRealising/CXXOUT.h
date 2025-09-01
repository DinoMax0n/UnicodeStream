#pragma once

#include "../Includes.h"

#ifdef _UNIX_ // For Unix Like OS
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

inline UnixCxxout& GetUnixCxxout() {
    static UnixCxxout instance;
    return instance;
} 
#endif 