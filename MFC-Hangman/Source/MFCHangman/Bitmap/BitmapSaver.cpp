#include "pch.h"
#include "MFCHangman/Bitmap/BitmapSaver.h"

#include "MFCHangman/Tools/PathGetter.h"

namespace MFCHangman::Bitmap {

BitmapSaver::BitmapSaver(CString folderName) : m_folder(folderName)
{
}

auto BitmapSaver::Save(CBitmap & bitmap, CString fileName) -> bool
{
    CImage image;
    image.Attach(bitmap.operator HBITMAP());

    CString rootPath = Tools::GetModuleFolderPath();

    CString path = rootPath + m_folder + fileName + _T(".bmp");

    HRESULT res = image.Save(path, Gdiplus::ImageFormatBMP);
    return true;
}
}
