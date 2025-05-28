#pragma once
#include "pch.h"
#include <vector>

namespace MFCHangman::Tools {
    auto HideWord(const CString& hiddenWord, 
        std::vector<TCHAR>& foundLetters) -> CString;
}