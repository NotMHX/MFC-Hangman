#include "pch.h"
#include <string>
#include "MFCHangman/Tools/GuessValidator.h"

namespace MFCHangman::Tools {

auto ValidateGuess(const CString& guess, std::vector<TCHAR>& foundLetters,
    std::vector<TCHAR>& wrongLetters, const CString& hiddenWord) -> bool
{
    if (WasLetterGuessedBefore(wrongLetters, guess, foundLetters) || IsGuessIllegal(guess)) {
        return true;
    }

    if (hiddenWord.Find(guess) != std::string::npos) {
        foundLetters.push_back(guess[0]);
        return true;
    } else {
        wrongLetters.push_back(guess[0]);
        return false;
    }
}

auto IsGuessIllegal(const CString& guess) -> bool
{
    if (guess.GetLength() > 1 || !std::isalpha(guess[0])) {
        AfxMessageBox(_T("Invalid guess. Make sure to only input *one* letter."), MB_ICONEXCLAMATION);
        return true;
    }
    return false;
}

auto WasLetterGuessedBefore(std::vector<WCHAR>& wrongLetters, const CString& guess,
    std::vector<WCHAR>& foundLetters) -> bool
{
    for (int i = 0; i < wrongLetters.size(); i++) {
        if (wrongLetters[i] == guess[0]) {
            return true;
        }
    }

    for (int i = 0; i < foundLetters.size(); i++) {
        if (foundLetters[i] == guess[0]) {
            return true;
        }
    }
    return false;
}

auto CheckWin(CString& currentWord, std::vector<TCHAR>& foundLetters) -> bool
{
    size_t charactersFound = 0;
    for (int i = 0; i < currentWord.GetLength(); ++i) {
        if (std::find(foundLetters.begin(), foundLetters.end(), currentWord.GetAt(i))
            != foundLetters.end()) {
            ++charactersFound;
        }
    }
    return charactersFound == currentWord.GetLength();
}
}