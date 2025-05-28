#include "pch.h"
#include "MFCHangman/Tools/WordHider.h"
#include "MFCHangman/Tools/GuessValidator.h"

namespace MFCHangman::Tools {

auto HideWord(const CString& hiddenWord, std::vector<TCHAR>& foundLetters) -> CString
{
    CString currentWord;

    for (int i = 0; i < hiddenWord.GetLength(); ++i) {
        bool printUnderscore = true;

        if (std::find(foundLetters.begin(), foundLetters.end(), hiddenWord.GetAt(i))
            != foundLetters.end()) {
            currentWord += hiddenWord.GetAt(i);
            printUnderscore = false;
        }

        if (printUnderscore) {
            currentWord += _T("_");
        }

        currentWord += _T(" ");
    }
    return currentWord;
}

}
