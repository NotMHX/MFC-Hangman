#include "pch.h"
#include "MFCHangman/Bitmap/BitmapManager.h"

#include "MFCHangman/Tools/PathGetter.h"
#include "MFCHangman/Tools/RectGetter.h"
#include "MFCHangman/Tools/FileNameGetter.h"

namespace MFCHangman::Bitmap {

BitmapManager::BitmapManager(BitmapLoader& loader, BitmapCreator& creator, BitmapSaver& saver)
    : m_loader(loader), m_creator(creator), m_saver(saver)
{
    for (int i = 0; i < 4; ++i) {
        m_bitmaps.emplace_back(std::make_unique<CBitmap>()); // allocate memory

        CString filename = Tools::GetFileNameFromDrawing(static_cast<Drawings>(i));
        const auto area = CRect(0, 0, 300, 300);

        if (!m_loader.DoesBitmapExist(filename) && m_bitmaps[i]) {
            m_creator.Create(*m_bitmaps[i], area, static_cast<Drawings>(i));
        } else {
            m_loader.Load(*m_bitmaps[i], filename);
        }

    }
}

auto BitmapManager::Show(Drawings drawing, CDC& canvasContext) -> void
{
    auto& image = m_bitmaps[static_cast<int>(drawing)];
    BITMAP imageProps;
    image->GetObject(sizeof(imageProps), &imageProps);

    CDC memoryDC;
    memoryDC.CreateCompatibleDC(&canvasContext);
    const auto oldBitmap = memoryDC.SelectObject(&*image);

    const auto area = Tools::GetDrawableRect(canvasContext);
    canvasContext.StretchBlt(area.left, area.top, area.Width(), area.Height(), &memoryDC,
        0, 0, imageProps.bmWidth, imageProps.bmHeight, SRCCOPY);

    memoryDC.SelectObject(oldBitmap);
}

BitmapManager::~BitmapManager()
{
    for (int i = 0; i < 4; ++i) {
        CString filename = Tools::GetFileNameFromDrawing(static_cast<Drawings>(i));

        if (!m_loader.DoesBitmapExist(filename)) {
            m_saver.Save(*m_bitmaps[i], filename);
        }
    }
}

}
