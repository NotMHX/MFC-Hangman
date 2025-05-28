#include "pch.h"
#include "MFCHangman/GameLogic.h"

#include "MFCHangman/DifficultyDlg.h"
#include "MFCHangman/WordBank.h"
#include "MFCHangman/Tools/GuessValidator.h"

namespace MFCHangman {

GameLogic::GameLogic(Data::GameData& data) : m_data(data)
{
}

auto GameLogic::TryInitGame(CWnd* pWnd) -> bool
{
    DifficultyDlg diffSelect(pWnd, m_data.Difficulty);
    if (diffSelect.DoModal() != IDOK) {
        return false;
    }

    m_data.WrongLetters = {};
    m_data.FoundLetters = {};
    SetAttempts();
    UpdateCurrentDrawing();
    if (GetRandomWordAndHint()) {
        return true;
    } else {
        AfxMessageBox(_T("Couldn't retrieve word from word list."), MB_ICONSTOP);
        return false;
    }
}

auto GameLogic::MakeGuess(CString guess, CWnd* pWnd) -> void
{
    if (Tools::ValidateGuess(guess, m_data.FoundLetters, m_data.WrongLetters, m_data.CurrentWord)) {
        if (Tools::CheckWin(m_data.CurrentWord, m_data.FoundLetters)) {
            AfxMessageBox(_T("You won! You found the word: ") + m_data.CurrentWord, MB_ICONINFORMATION);
            ++m_data.GamesPlayed;
            ++m_data.GamesWon;
            pWnd->SendMessage(WM_CLOSE);
        }
    } else {
        --m_data.AttemptsLeft;
        if (m_data.AttemptsLeft <= 0) {
            ++m_data.GamesPlayed;
            ++m_data.GamesLost;
            AfxMessageBox(_T("You lost. The hidden word was: ") + m_data.CurrentWord, MB_ICONINFORMATION);
            pWnd->SendMessage(WM_CLOSE);
        }
    }
}

auto GameLogic::UpdateCurrentDrawing() -> void
{
    switch (m_data.AttemptsLeft) {
        case 5:
        case 4:
            m_data.CurrentDrawing = Drawings::Base;
            return;
        case 3:
        case 2:
            m_data.CurrentDrawing = Drawings::Pole;
            return;
        case 1:
            m_data.CurrentDrawing = Drawings::Hanger;
            return;
        case 0:
        default:
            m_data.CurrentDrawing = Drawings::Man;
            return;
    }
}

auto GameLogic::SetAttempts() -> void
{
    switch (m_data.Difficulty) {
        case Data::Difficulty::Easy:
            m_data.AttemptsLeft = EasyAttempts;
            break;
        case Data::Difficulty::Medium:
            m_data.AttemptsLeft = MediumAttempts;
            break;
        case Data::Difficulty::Hard:
            m_data.AttemptsLeft = HardAttempts;
            break;
    }
}

auto GameLogic::GetRandomWordAndHint() -> bool
{
    WordBank wb(m_data.Difficulty);

    if (wb.ReadWordsFromFile()) {
        int rng = wb.GetRandomIndex();
        m_data.CurrentWord = wb.GetWord(rng);
        m_data.CurrentHint = wb.GetHint(rng);
        return true;
    } else {
        m_data.CurrentWord = _T("");
        m_data.CurrentHint = _T("");
        return false;
    }
}
}