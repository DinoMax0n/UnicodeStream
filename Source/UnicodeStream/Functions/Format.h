/*
ATTENTION!!!!!
These functions are made for formatting text outside the library library this file is not used
INCLUDE ME !!!
*/
#pragma once

#include "../Includes.h"
#include "../Lib/utf8cpp/utf8.h"
#include <type_traits>
#include <iterator>

namespace dm {
    namespace Format {

        template <typename T>
        std::string ToString(const T& value) {
            if constexpr (std::is_same_v<T, std::string>) {
                return value;
            }
            else if constexpr (std::is_same_v<T, const char*> || std::is_same_v<T, char>) {
                return std::string(value);
            }
            else if constexpr (std::is_same_v<T, std::wstring>) {
                std::string result;
                utf8::utf32to8(value.begin(), value.end(), std::back_inserter(result));
                return result;
            }
            else if constexpr (std::is_same_v<T, wchar_t>) {
                std::wstring wstr(1, value);
                std::string result;
                utf8::utf32to8(wstr.begin(), wstr.end(), std::back_inserter(result));
                return result;
            }
            else if constexpr (std::is_same_v<T, bool>) {
                return value ? "true" : "false";
            }
            else {
                return std::to_string(value); 
            }
        }

        template <typename T>
        std::wstring ToWstring(const T& value) {
            if constexpr (std::is_same_v<T, std::wstring>) {
                return value;
            }
            else if constexpr (std::is_same_v<T, wchar_t>) {
                return std::wstring(1, value);
            }
            else if constexpr (std::is_same_v<T, std::string> || std::is_same_v<T, const char*> || std::is_same_v<T, char>) {
                std::string str = std::string(value);
                std::wstring result;
                utf8::utf8to32(str.begin(), str.end(), std::back_inserter(result));
                return result;
            }   
            else if constexpr (std::is_same_v<T, bool>) {
                return value ? L"true" : L"false";
            }
            else {
                return std::to_wstring(value); 
            }
        }
    }
}