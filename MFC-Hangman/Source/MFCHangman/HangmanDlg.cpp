#include "pch.h"
#include "resource.h"
#include "MFCHangman/HangmanDlg.h"

#include "MFCHangman/Tools/WordHider.h"
#include "MFCHangman/Tools/GuessValidator.h"
#include "MFCHangman/Tools/StringFormatter.h"

namespace MFCHangman {

HangmanDlg::HangmanDlg(CWnd* pParent, GameLogic& logic, Data::GameData& data)
    : CDialogEx(IDD_HANGMAN, pParent), m_logic(logic), m_data(data)
{
}

auto HangmanDlg::UpdateHiddenWordBox() -> void
{
    CString hiddenWord = Tools::HideWord(m_data.CurrentWord, m_data.FoundLetters);
    m_hiddenWordBox.SetWindowText(hiddenWord);
}

auto HangmanDlg::UpdateHintBox() -> void
{
    m_hintBox.SetWindowText(m_data.CurrentHint);
}

auto HangmanDlg::UpdateAttemptsLeftBox() -> void
{
    CString attemptsStr;
    attemptsStr.Format(_T("%d"), m_data.AttemptsLeft);
    m_attemptsBox.SetWindowText(attemptsStr);
}

auto HangmanDlg::UpdateWrongLettersBox() -> void
{
    CString wrongLettersStr = Tools::FormatWrongLettersToString(m_data.WrongLetters);
    m_wrongsBox.SetWindowText(wrongLettersStr);
}

auto HangmanDlg::ClearGuessBox() -> void
{
    m_guessBox.SetWindowText(_T(""));
}

auto HangmanDlg::OnInitDialog() -> BOOL
{
    __super::OnInitDialog();

    if (!m_logic.TryInitGame(m_pParentWnd)) {
        SendMessage(WM_CLOSE);
    }
    UpdateDynamicFields();
    UpdateHintBox();

    if (!m_statusBar.Create(this)) {
        TRACE("Failed to create status bar\n");
        return FALSE;
    }

    m_statusBar.SetIndicators(NULL, 3);
    CRect rect;
    GetClientRect(rect);
    int paneWidth = rect.Width() / 3;
    m_statusBar.SetPaneInfo(0, static_cast<int>(Elements::IDS_GAMESPLAYED), SBPS_STRETCH, paneWidth);
    m_statusBar.SetPaneInfo(1, static_cast<int>(Elements::IDS_WONGAMES), SBPS_STRETCH, paneWidth);
    m_statusBar.SetPaneInfo(2, static_cast<int>(Elements::IDS_LOSTGAMES), SBPS_STRETCH, paneWidth);

    CString playedText;
    playedText.Format(_T("Games played: %zu"), m_data.GamesPlayed);
    m_statusBar.SetPaneText(0, playedText);

    CString wonText;
    wonText.Format(_T("Wins: %zu"), m_data.GamesWon);
    m_statusBar.SetPaneText(1, wonText);

    CString lostText;
    lostText.Format(_T("Losses: %zu"), m_data.GamesLost);
    m_statusBar.SetPaneText(2, lostText);

    return TRUE;
}

BEGIN_MESSAGE_MAP(HangmanDlg, CDialogEx)
    ON_WM_PAINT()
    ON_WM_SIZE()
    ON_BN_CLICKED(static_cast<int>(Elements::IDC_GO), OnClickGo)
END_MESSAGE_MAP()

void HangmanDlg::OnPaint()
{
    __super::OnPaint();

    if (IsWindowVisible() == TRUE) {
        CClientDC canvas(&m_bitmapBox);
        m_data.ShowFunc(m_data.CurrentDrawing, canvas);
    }
}

void HangmanDlg::OnSize(UINT nType, int cx, int cy)
{
    __super::OnSize(nType, cx, cy);

    if (IsWindowVisible() == TRUE) {
        CRect rect;
        GetClientRect(rect);
        m_statusBar.SetWindowPos(this, rect.left, rect.top, rect.Width(), rect.Height(), SWP_SHOWWINDOW);

        UpdateBitmap();
    }
}

auto HangmanDlg::OnClickGo() -> void
{
    CString guess;
    m_guessBox.GetWindowText(guess);
    m_logic.MakeGuess(guess, this);

    UpdateDynamicFields();
    ClearGuessBox();
    UpdateBitmap();
}

void HangmanDlg::UpdateBitmap()
{
    m_logic.UpdateCurrentDrawing();
    Invalidate();
    UpdateWindow();
}

void HangmanDlg::OnOK()
{
    if (GetFocus() == GetDlgItem(static_cast<int>(Elements::IDE_GUESS))) {
        OnClickGo();
        return;
    }
}

void HangmanDlg::UpdateDynamicFields()
{
    UpdateHiddenWordBox();
    UpdateAttemptsLeftBox();
    UpdateWrongLettersBox();
}

auto HangmanDlg::DoDataExchange(CDataExchange * pDX) -> void
{
    __super::DoDataExchange(pDX);

    DDX_Control(pDX, static_cast<int>(Elements::IDC_PICTCTRL), m_bitmapBox);
    DDX_Control(pDX, static_cast<int>(Elements::IDT_HIDDENWORD), m_hiddenWordBox);
    DDX_Control(pDX, static_cast<int>(Elements::IDT_HINT), m_hintBox);
    DDX_Control(pDX, static_cast<int>(Elements::IDT_ATTEMPTS), m_attemptsBox);
    DDX_Control(pDX, static_cast<int>(Elements::IDT_WRONGLETTERS), m_wrongsBox);
    DDX_Control(pDX, static_cast<int>(Elements::IDE_GUESS), m_guessBox);
}

}
