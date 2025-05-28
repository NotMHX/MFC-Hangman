#pragma once
#include "pch.h"

#include "MFCHangman/HangmanPainter.h"

namespace MFCHangman::Bitmap {

class BitmapCreator {
public:
    BitmapCreator();

    auto Create(CBitmap& bitmap, CRect rect, Drawings drawing) -> bool;

private:
};
}