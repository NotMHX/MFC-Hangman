#include "pch.h"
#include "MFCHangman/Tools/PathGetter.h"

namespace MFCHangman::Tools {

auto GetModuleFolderPath() -> CString
{
    CString currentPath;
    TCHAR path[MAX_PATH];

    if (GetModuleFileName(NULL, path, MAX_PATH) != 0) {
        PathRemoveFileSpec(path);
        currentPath = path;
        currentPath += _T("\\HangmanFiles");
    }
    return currentPath;
}
}