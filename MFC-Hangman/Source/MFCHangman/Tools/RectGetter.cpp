#include "pch.h"
#include "MFCHangman/Tools/RectGetter.h"

namespace MFCHangman::Tools {

auto GetDrawableRect(CDC& dc) -> CRect
{
    auto window = WindowFromDC(dc);
    CRect pRect;
    if (window != nullptr) {
        CRect tempRect;
        if (GetClientRect(window, &tempRect) == TRUE) {
            pRect = tempRect;
        } else {
            ASSERT(_T("can't retrieve client canvas"));
        }
    } else {
        ASSERT(_T("can't locate a window"));
    }

    return pRect;
}

}
