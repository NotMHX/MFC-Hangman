#pragma once
#include "pch.h"

#include "MFCHangman/Data/Difficulty.h"
#include "MFCHangman/Data/GameData.h"
#include "MFCHangman/Drawings.h"

namespace MFCHangman {

constexpr int EasyAttempts = 5;
constexpr int MediumAttempts = 4;
constexpr int HardAttempts = 3;

class GameLogic {
public:
    GameLogic(Data::GameData& data);
    auto TryInitGame(CWnd* pWnd) -> bool;
    auto MakeGuess(CString guess, CWnd* pWnd) -> void;
    auto UpdateCurrentDrawing() -> void;

private:
    auto SetAttempts() -> void;
    auto GetRandomWordAndHint() -> bool;

    Data::GameData& m_data;
};
}
