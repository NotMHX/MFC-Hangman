#pragma once

#include "pch.h"
#include <vector>

namespace MFCHangman::Tools {

auto ValidateGuess(const CString& guess, std::vector<TCHAR>& foundLetters,
    std::vector<TCHAR>& wrongLetters, const CString& hiddenWord) -> bool;

auto IsGuessIllegal(const CString& guess) -> bool;

auto WasLetterGuessedBefore(std::vector<WCHAR>& wrongLetters, const CString& guess,
    std::vector<WCHAR>& foundLetters) -> bool;

auto CheckWin(CString& hiddenWord, std::vector<TCHAR>& foundLetters) -> bool;
}
