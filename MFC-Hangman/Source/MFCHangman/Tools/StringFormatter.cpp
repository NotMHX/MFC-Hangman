#include "pch.h"
#include "MFCHangman/Tools/StringFormatter.h"

namespace MFCHangman::Tools {

auto FormatWrongLettersToString(std::vector<TCHAR>& wrongLetters) -> CString
{
    if (!wrongLetters.empty()) {
        CString wrongLettersStr;
        for (size_t i = 0; i < wrongLetters.size(); ++i) {
            CString current;
            current.Format(_T("%c"), wrongLetters[i]);
            wrongLettersStr += current;

            if (i < wrongLetters.size() - 1) {
                wrongLettersStr += _T(", ");
            }
        }
        return wrongLettersStr;
    }
    return _T("No wrong guesses yet.");
}

}