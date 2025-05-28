#include "pch.h"
#include "MFCHangman/Bitmap/BitmapCreator.h"

namespace MFCHangman::Bitmap {

BitmapCreator::BitmapCreator()
{
}

auto BitmapCreator::Create(CBitmap& bitmap, CRect rect, Drawings drawing) -> bool
{
    CSize windowSize(rect.Width(), rect.Height());

    CDC blankContext;
    blankContext.CreateCompatibleDC(nullptr);

    if (blankContext.GetSafeHdc() == nullptr) {
        return false;
    }

    if (bitmap.CreateCompatibleBitmap(&blankContext, windowSize.cx, windowSize.cy)) {
        const auto oldBitmap = blankContext.SelectObject(&bitmap);
        HangmanPainter painter(blankContext, rect);
        painter.Paint(drawing);

        blankContext.SelectObject(oldBitmap);

        return true;
    }

    return false;
}
}