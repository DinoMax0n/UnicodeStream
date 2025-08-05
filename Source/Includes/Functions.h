#pragma once
#define FMT_HEADER_ONLY
#include "Includes.h"
#include "Lib/fmt/format.h"
#include "Lib/fmt/xchar.h"

template <typename T>
std::wstring FormatToWstring(const T& Value) { // Convert Anyone to Wstring;
    return fmt::format(L"{}", Value);
}