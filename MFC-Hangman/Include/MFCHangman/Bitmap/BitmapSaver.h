#pragma once
#include "pch.h"

namespace MFCHangman::Bitmap {

class BitmapSaver {
public:
    BitmapSaver(CString folderName);

    auto Save(CBitmap& bitmap, CString fileName) -> bool;
private:
    CString m_folder;
};
}
