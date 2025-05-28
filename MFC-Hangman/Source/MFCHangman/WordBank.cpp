#include "pch.h"
#include "MFCHangman/WordBank.h"

#include <random>
#include <vector>
#include <fstream>
#include <string>
#include <utility>
#include "MFCHangman/Data/Difficulty.h"
#include "MFCHangman/Tools/PathGetter.h"

namespace MFCHangman {

WordBank::WordBank(Data::Difficulty d)
{
    CString currentPath = Tools::GetModuleFolderPath();
    currentPath += _T("\\Words\\");

    switch (d) {
        case Data::Difficulty::Easy:
            m_fileName = currentPath + _T("Easy.txt");
            break;
        case Data::Difficulty::Medium:
            m_fileName = currentPath + _T("Medium.txt");
            break;
        case Data::Difficulty::Hard:
            m_fileName = currentPath + _T("Hard.txt");
            break;
    }
}

auto WordBank::ReadWordsFromFile() -> bool
{
    std::ifstream file(m_fileName);

    if (!file.is_open()) {
        return false;
    }

    std::string currentLine;
    int i = 0;

    while (std::getline(file, currentLine)) {
        std::pair<std::string, std::string> items;
        int pos = 0;
        std::string item;

        while ((pos = currentLine.find(':')) != std::string::npos) {
            item = currentLine.substr(0, pos);
            items.first = item;
            currentLine.erase(0, pos + 1);
        }
        items.second = currentLine;

        // set list items
        m_words[i] = (items.first).c_str();
        if (items.second.empty()) { // check if there is no hint
            m_hints[i] = _T("No hint provided :(");
        } else {
            m_hints[i] = (items.second).c_str();
        }
        ++i;
    }
    file.close();
    m_numberOfEntries = i;
    return true;
}

auto WordBank::GetRandomIndex() -> int
{
    std::random_device r;
    std::mt19937 rng(r());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0, m_numberOfEntries - 1);

    return dist6(rng);
}

auto WordBank::GetWord(int index) -> CString
{
    if (index > -1 && index < m_numberOfEntries) {
        return m_words[index];
    } else {
        return _T("");
    }
}

auto WordBank::GetHint(int index) -> CString
{
    if (index > -1 && index < m_numberOfEntries) {
        return m_hints[index];
    } else {
        return _T("");
    }
}

}
