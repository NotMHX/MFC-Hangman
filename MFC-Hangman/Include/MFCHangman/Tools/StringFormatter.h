#pragma once
#include "pch.h"
#include <vector>

namespace MFCHangman::Tools {

auto FormatWrongLettersToString(std::vector<TCHAR>& wrongLetters) -> CString;

}