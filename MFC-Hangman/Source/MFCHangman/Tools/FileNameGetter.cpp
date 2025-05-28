#include "pch.h"
#include "MFCHangman/Tools/FileNameGetter.h"

namespace MFCHangman::Tools {

auto GetFileNameFromDrawing(const Drawings drawing) -> CString
{
    switch (drawing) {
        case Drawings::Base:
            return _T("base");
        case Drawings::Pole:
            return _T("pole");
        case Drawings::Hanger:
            return _T("hanger");
        case Drawings::Man:
            return _T("man");
        default:
            return _T("unknown");
    }
}
}