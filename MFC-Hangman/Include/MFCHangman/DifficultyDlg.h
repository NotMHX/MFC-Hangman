#pragma once
#include "pch.h"

#include "MFCHangman/Data/Difficulty.h"

namespace MFCHangman {

class DifficultyDlg : public CDialogEx {
public:
    DifficultyDlg(CWnd* pParent, Data::Difficulty& diff);

    enum Buttons {
        Idc_Easy = 101,
        Idc_Medium = 102,
        Idc_Hard = 103
    };
    DECLARE_MESSAGE_MAP();

private:
    auto OnBtnClickEasy() -> void;
    auto OnBtnClickMedium() -> void;
    auto OnBtnClickHard() -> void;

    Data::Difficulty& m_diff;
};
}