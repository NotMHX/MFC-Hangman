#pragma once
#include "pch.h"

#include "MFCHangman/Drawings.h"

namespace MFCHangman::Bitmap {

class BitmapLoader {
public:
    BitmapLoader(CString folder);

    auto Load(CBitmap& bitmap, CString fileName) -> bool;
    auto DoesBitmapExist(const CString filename) -> bool;
private:
    CString m_folder;
};
}