#include "core_imgui_state.h"

#if defined(CORE_GL) && defined(CORE_WIN)

#include "core_backend/opengl/backend/win32/win32_gl_imgui.h"

namespace ImGui
{
    void Init(const IWindow& window)
    {
        // @Note: We assume a valid opengl rendering context created here.
        HGLRC hglrc = wglGetCurrentContext();
        HDC hdc = wglGetCurrentDC();
        HWND hwnd = reinterpret_cast<HWND>(window.handle());
        Init_Win32_GL3(hwnd, hdc, hglrc);
    }
    
    void Begin_Drawing()
    {
        Begin_Frame_Win32_GL3();
    }

    void End_Drawing()
    {
        End_Frame_Win32_GL3();
    }

    void Deinit()
    {
        Deinit_Win32_GL3();
    }
}

#endif