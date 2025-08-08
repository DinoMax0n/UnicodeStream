#pragma once
#include "UnicodeStreamIncludes.h"
#include "Lib/utf8cpp/utf8.h"


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
std::string FormatToString (const T& Value) {
    std::wstring wstr = FormatToWstring(Value);
    std::string utf8result;
    utf8::utf16to8(wstr.begin(), wstr.end(), std::back_inserter(utf8result));
    return utf8result;
}
