#pragma once
#include "pch.h"

#include "MFCHangman/Drawings.h"

namespace MFCHangman {

class HangmanPainter {
public:
    HangmanPainter(CDC& deviceContext, CRect canvas);

    auto Paint(Drawings drawing) -> void;
private:
    auto PaintBase() -> void;
    auto PaintPole() -> void;
    auto PaintHanger() -> void;
    auto PaintMan() -> void;

    CDC& m_context;
    CRect m_canvasRect;
};

}