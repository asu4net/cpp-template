
#include "app_imgui.h"

#if defined(GAME_WIN) && defined(GAME_GL)
#   include "app_imgui_win32_gl.h"
#endif

auto app_imgui_init(const IWindow& window) -> void
{
#if defined(GAME_WIN) && defined(GAME_GL)
        HGLRC hglrc = wglGetCurrentContext();
        HDC hdc = wglGetCurrentDC();
        HWND hwnd = reinterpret_cast<HWND>(window.handle());
        app_imgui_init_win32_gl(hwnd, hdc, hglrc);
#endif
}

auto app_imgui_done() -> void
{
#if defined(GAME_WIN) && defined(GAME_GL)
    app_imgui_done_win32_gl();
#endif
}

auto app_imgui_begin() -> void
{
#if defined(GAME_WIN) && defined(GAME_GL)
    app_imgui_begin_win32_gl();
#endif
}

auto app_imgui_end() -> void
{
#if defined(GAME_WIN) && defined(GAME_GL)
    app_imgui_end_win32_gl();
#endif
} 