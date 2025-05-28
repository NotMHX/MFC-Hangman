#include "pch.h"
#include "MFCHangman/MFCHangman.h"

#include "MFCHangman/HangmanDlg.h"
#include "MFCHangman/GameLogic.h"
#include "MFCHangman/Bitmap/BitmapManager.h"

namespace MFCHangman {

Data::GameData myOnlyData;

void InitGame(CWnd* pWnd)
{
    const CString drawingPath = _T("\\Drawings\\");

    Bitmap::BitmapLoader loader(drawingPath);
    Bitmap::BitmapCreator creator;
    Bitmap::BitmapSaver saver(drawingPath);
    Bitmap::BitmapManager manager(loader, creator, saver);

    myOnlyData.ShowFunc = [&](Drawings drawing, CDC& dc) {
        manager.Show(drawing, dc);
        };

    GameLogic gameLogic(myOnlyData);
    HangmanDlg hangmanInstance(pWnd, gameLogic, myOnlyData);
    hangmanInstance.DoModal();
}
}
