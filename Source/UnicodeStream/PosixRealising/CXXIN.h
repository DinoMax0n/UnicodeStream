#pragma once

#include "../Includes.h"
#include "Parser.h"

#ifdef _UNIX_ // For Unix Like OS
#include <unistd.h>
class UnixCxxin;
inline UnixCxxin& GetUnixCxxin();

class UnixCxxin {
    private:
        UnixCxxin() = default;
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

inline UnixCxxin& GetUnixCxxin() {
    static UnixCxxin instance;
    return instance;
} 


#endif 
