#pragma once

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>

namespace ImGui
{
    void Init_Win32_GL3(HWND hwnd, HDC hdc, HGLRC hglrc);
    void Begin_Frame_Win32_GL3();
    void End_Frame_Win32_GL3();
    void Deinit_Win32_GL3();
}
