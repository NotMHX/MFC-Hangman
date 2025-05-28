#pragma once
#include "pch.h"

#include "MFCHangman/GameLogic.h"
#include "MFCHangman/Data/GameData.h"

namespace MFCHangman {

class HangmanDlg : public CDialogEx {
public:
    HangmanDlg(CWnd* pParent, GameLogic& logic, Data::GameData& data);

    auto UpdateHiddenWordBox() -> void;
    auto UpdateHintBox() -> void;
    auto UpdateAttemptsLeftBox() -> void;
    auto UpdateWrongLettersBox() -> void;
    auto ClearGuessBox() -> void;

protected:
    auto OnInitDialog() -> BOOL override;
    afx_msg void OnPaint();
    afx_msg void OnSize(UINT nType, int cx, int cy);

    void UpdateBitmap();

    auto OnClickGo() -> void;
    virtual void OnOK();
    void UpdateDynamicFields();

    auto DoDataExchange(CDataExchange* pDX) -> void override;	// DDX/DDV support
private:
    DECLARE_MESSAGE_MAP();
    CStatusBar m_statusBar;

    GameLogic& m_logic;
    Data::GameData& m_data;

    enum class Elements {
        IDC_PICTCTRL = 101,
        IDT_HIDDENWORD = 201,
        IDT_HINT = 202,
        IDT_ATTEMPTS = 203,
        IDT_WRONGLETTERS = 204,
        IDE_GUESS = 301,
        IDC_GO = 302,
        IDS_GAMESPLAYED = 401,
        IDS_WONGAMES = 402,
        IDS_LOSTGAMES = 403
    };
    CStatic m_bitmapBox;
    CStatic m_hiddenWordBox;
    CStatic m_hintBox;
    CStatic m_attemptsBox;
    CStatic m_wrongsBox;
    CEdit m_guessBox;
};
}