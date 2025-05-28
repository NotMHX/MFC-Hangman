#include "pch.h"
#include "resource.h"

#include "MFCHangman/DifficultyDlg.h"

namespace MFCHangman {

DifficultyDlg::DifficultyDlg(CWnd* pParent, Data::Difficulty& diff)
    : CDialogEx(IDD_DIFFICULTY, pParent), m_diff(diff)
{
}

BEGIN_MESSAGE_MAP(DifficultyDlg, CDialogEx)
    ON_BN_CLICKED(static_cast<int>(Buttons::Idc_Easy), OnBtnClickEasy)
    ON_BN_CLICKED(static_cast<int>(Buttons::Idc_Medium), OnBtnClickMedium)
    ON_BN_CLICKED(static_cast<int>(Buttons::Idc_Hard), OnBtnClickHard)
END_MESSAGE_MAP()

auto DifficultyDlg::OnBtnClickEasy() -> void
{
    m_diff = Data::Difficulty::Easy;
    __super::OnOK();
}

auto DifficultyDlg::OnBtnClickMedium() -> void
{
    m_diff = Data::Difficulty::Medium;
    __super::OnOK();
}

auto DifficultyDlg::OnBtnClickHard() -> void
{
    m_diff = Data::Difficulty::Hard;
    __super::OnOK();
}

}
