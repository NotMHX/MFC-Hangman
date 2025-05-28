#pragma once
#include "pch.h"

#include <iostream>
#include <fstream>
#include "MFCHangman/GameLogic.h"
#include "MFCHangman/Data/Difficulty.h"

namespace MFCHangman {

class WordBank {
public:
    WordBank(Data::Difficulty d);
    auto ReadWordsFromFile() -> bool;

    auto GetRandomIndex() -> int;

    auto GetWord(int index) -> CString;
    auto GetHint(int index) -> CString;

    friend class WordModifier;
private:
    int m_numberOfEntries = 0;
    CString m_words[50];
    CString m_hints[50];
    CString m_fileName;
};

}