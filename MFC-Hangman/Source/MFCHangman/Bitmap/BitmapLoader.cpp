#include "pch.h"
#include "MFCHangman/Bitmap/BitmapLoader.h"

#include <Shlwapi.h>
#include "MFCHangman/Tools/PathGetter.h"
#pragma comment(lib, "Shlwapi.lib")

namespace MFCHangman::Bitmap {

BitmapLoader::BitmapLoader(CString folderName) : m_folder(folderName)
{
}

auto BitmapLoader::Load(CBitmap& bitmap, CString fileName) -> bool
{
    CString rootPath = Tools::GetModuleFolderPath();
    CString path = rootPath + m_folder + fileName + _T(".bmp");

    CImage loader;
    loader.Load(path);
    return bitmap.Attach(loader.Detach()) == TRUE;
}

auto BitmapLoader::DoesBitmapExist(const CString filename) -> bool
{
    const auto rootPath = Tools::GetModuleFolderPath();

    CString path = rootPath + m_folder + filename + _T(".bmp");

    return GetFileAttributes(path) != INVALID_FILE_ATTRIBUTES;
}

}