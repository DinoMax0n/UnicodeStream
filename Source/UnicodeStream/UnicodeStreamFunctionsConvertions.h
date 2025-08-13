#pragma once
#include "UnicodeStreamIncludes.h"
#include "Lib/utf8cpp/utf8.h"
#include <variant>
#include <algorithm>
#include <stdexcept>


template <typename T>
std::wstring FormatToWstring(const T& Value) {
    if constexpr (std::is_same_v<T, std::string>) {
        std::wstring result;
        utf8::utf8to32(Value.begin(), Value.end(), std::back_inserter(result));
        return result;

    } else if constexpr (std::is_convertible_v<T, const char*>) {
        std::string str(Value);
        std::wstring result;
        utf8::utf8to32(str.begin(), str.end(), std::back_inserter(result));
        return result;

    } else if constexpr (std::is_same_v<T, char>) {
        std::string str(1, Value);
        std::wstring result;
        utf8::utf8to32(str.begin(), str.end(), std::back_inserter(result));
        return result;

    } else {
        return std::to_wstring(Value);
    }
}

template <typename T>
std::vector<char> FormatToString(const T& value) {
    std::string utf8;

    if constexpr (std::is_same_v<T, std::wstring>) {
        utf8::utf32to8(value.begin(), value.end(), std::back_inserter(utf8));
    }
    else if constexpr (std::is_same_v<T, wchar_t>) {
        std::wstring wstr(1, value);
        utf8::utf32to8(wstr.begin(), wstr.end(), std::back_inserter(utf8));
    }
    else {
        utf8 = std::to_string(value); 
    }

    return std::vector<char>(utf8.begin(), utf8.end());
}

template <typename T>
T ParsedValue(const std::vector<wchar_t>& Input) {
    std::wstring wstr(Input.begin(), Input.end());

    if constexpr (std::is_same_v<T, bool>) {
        if (wstr == L"true") {
            return true;
        } else if (wstr == L"false") {
            return false;
        } else {
            throw std::invalid_argument("Invalid boolean string");
        }
    }
    else if constexpr (std::is_same_v<T, int>) {
        try {
            return std::stoi(wstr);
        } catch (...) {
            throw std::invalid_argument("Invalid int string");
        }
    }
    else if constexpr (std::is_same_v<T, float>) {
        try {
            return std::stof(wstr);
        } catch (...) {
            throw std::invalid_argument("Invalid float string");
        }
    }
    else if constexpr (std::is_same_v<T, std::string>) {
        std::string Result;
        utf8::utf16to8(wstr.begin(), wstr.end(), std::back_inserter(Result));
        return Result;
    }
    else {
        static_assert(sizeof(T) == 0, "Unsupported type for conversion");
    }
}