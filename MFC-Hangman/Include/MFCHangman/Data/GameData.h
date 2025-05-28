#pragma once
#include "pch.h"

#include <vector>
#include <functional>
#include "MFCHangman/Data/Difficulty.h"
#include "MFCHangman/Drawings.h"

namespace MFCHangman::Data {

struct GameData {
    Difficulty Difficulty {};
    int AttemptsLeft {};

    CString CurrentWord {};
    CString CurrentHint {};

    std::vector<TCHAR> FoundLetters {};
    std::vector<TCHAR> WrongLetters {};

    Drawings CurrentDrawing {};
    std::function<void(Drawings, CDC&)> ShowFunc {};

    size_t GamesPlayed = 0;
    size_t GamesWon = 0;
    size_t GamesLost = 0;
};
}
