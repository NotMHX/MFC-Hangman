#include "pch.h"
#include "MFCHangman/HangmanPainter.h"

#include "MFCHangman/Tools/RectGetter.h"

namespace MFCHangman {

HangmanPainter::HangmanPainter(CDC& deviceContext, CRect canvas)
    : m_context(deviceContext), m_canvasRect(canvas)
{
}

auto HangmanPainter::Paint(Drawings drawing) -> void
{
    CPen pen(PS_SOLID, 1, RGB(0, 0, 0));
    const auto orgPen = m_context.SelectObject(&pen);

    m_context.FillSolidRect(m_canvasRect, RGB(255, 255, 255));

    switch (drawing) { // Fallthrough is intentional!
        case Drawings::Man:
            PaintMan();
        case Drawings::Hanger:
            PaintHanger();
        case Drawings::Pole:
            PaintPole();
        case Drawings::Base:
            PaintBase();
        default:
            break;
    }

    m_context.SelectObject(orgPen);
}

auto HangmanPainter::PaintBase() -> void
{
    int height = m_canvasRect.bottom - (m_canvasRect.Width() / 20);
    m_context.MoveTo(m_canvasRect.left, height);
    m_context.LineTo(m_canvasRect.left + (m_canvasRect.Width() / 10), height); // bottom horizontal line
}

auto HangmanPainter::PaintPole() -> void
{
    m_context.MoveTo(m_canvasRect.left + (m_canvasRect.Width() / 20), m_canvasRect.bottom - (m_canvasRect.Width() / 20));
    m_context.LineTo(m_canvasRect.left + (m_canvasRect.Width() / 20), m_canvasRect.top + (m_canvasRect.Height() / 10)); // to top left
}

auto HangmanPainter::PaintHanger() -> void
{
    m_context.MoveTo(m_canvasRect.left + (m_canvasRect.Width() / 20), m_canvasRect.top + (m_canvasRect.Height() / 10));
    m_context.LineTo((m_canvasRect.right - m_canvasRect.Width() / 8), m_canvasRect.top + (m_canvasRect.Height() / 10)); // to top right
    m_context.LineTo((m_canvasRect.right - m_canvasRect.Width() / 8), m_canvasRect.top + (m_canvasRect.Height() / 5)); // to beginning of head
}

auto HangmanPainter::PaintMan() -> void
{
    // head
    CPoint topLeft((m_canvasRect.right - m_canvasRect.Width() / 6), m_canvasRect.top + (m_canvasRect.Height() / 5));
    CPoint bottomRight((m_canvasRect.right - m_canvasRect.Width() / 12), m_canvasRect.top + (m_canvasRect.Height() / 3));
    m_context.Ellipse(CRect(topLeft, bottomRight));

    // body
    m_context.MoveTo((m_canvasRect.right - m_canvasRect.Width() / 8), m_canvasRect.top + (m_canvasRect.Height() / 3));
    m_context.LineTo((m_canvasRect.right - m_canvasRect.Width() / 8), m_canvasRect.bottom - (m_canvasRect.Height() / 3));

    // legs
    m_context.LineTo((m_canvasRect.right - m_canvasRect.Width() / 6), m_canvasRect.bottom - (m_canvasRect.Height() / 5));
    m_context.MoveTo((m_canvasRect.right - m_canvasRect.Width() / 8), m_canvasRect.bottom - (m_canvasRect.Height() / 3));
    m_context.LineTo((m_canvasRect.right - m_canvasRect.Width() / 12), m_canvasRect.bottom - (m_canvasRect.Height() / 5));
}

}
