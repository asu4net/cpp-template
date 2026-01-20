#pragma once
#include "core_window.h"

namespace ImGui
{
    void Init(const IWindow& window);
    void Begin_Drawing();
    void End_Drawing();
    void Deinit();
}
