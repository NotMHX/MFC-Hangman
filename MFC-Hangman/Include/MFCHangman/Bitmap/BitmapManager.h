#pragma once
#include "pch.h"

#include <vector>
#include <memory>
#include "MFCHangman/Bitmap/BitmapLoader.h"
#include "MFCHangman/Bitmap/BitmapCreator.h"
#include "MFCHangman/Bitmap/BitmapSaver.h"
#include "MFCHangman/Drawings.h"

namespace MFCHangman::Bitmap {

class BitmapManager {
public:
    BitmapManager(BitmapLoader& loader, BitmapCreator& creator, BitmapSaver& saver);
    auto Show(Drawings drawing, CDC& dc) -> void;
    virtual ~BitmapManager();

private:
    BitmapLoader& m_loader;
    BitmapCreator& m_creator;
    BitmapSaver& m_saver;
    std::vector<std::unique_ptr<CBitmap>> m_bitmaps;
};
}