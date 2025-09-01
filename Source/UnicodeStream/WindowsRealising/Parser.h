#pragma once

#include "../Includes.h"

template <typename T>
T ParsedWinValue(const std::vector<wchar_t>& Input) {
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