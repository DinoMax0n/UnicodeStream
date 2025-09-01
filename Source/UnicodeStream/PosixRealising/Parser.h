#pragma once

#include "../Includes.h"

template <typename T>
T ParsedUnixValue(const std::vector<char>& Input) {
    std::string str(Input.begin(), Input.end());

    if constexpr (std::is_same_v<T, bool>) {
        if (str == "true") {
            return true;
        } else if (str == "false") {
            return false;
        } else {
            throw std::invalid_argument("Invalid boolean string");
        }
    }
    else if constexpr (std::is_same_v<T, int>) {
        try {
            return std::stoi(str);
        } catch (...) {
            throw std::invalid_argument("Invalid int string");
        }
    }
    else if constexpr (std::is_same_v<T, float>) {
        try {
            return std::stof(str);
        } catch (...) {
            throw std::invalid_argument("Invalid float string");
        }
    }
    else if constexpr (std::is_same_v<T, std::string>) {
        return str; 
    }
    else {
        static_assert(sizeof(T) == 0, "Unsupported type for conversion");
    }
}