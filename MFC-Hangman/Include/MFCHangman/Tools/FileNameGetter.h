#pragma once
#include "pch.h"

#include "MFCHangman/Drawings.h"

namespace MFCHangman::Tools {

auto GetFileNameFromDrawing(const Drawings drawing) -> CString;

}