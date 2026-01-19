#pragma once

#ifdef PFM_WIN

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#ifdef API_GL
#include "core/backend/opengl/backend/win32/win32_gl_context.h"
#endif

#include "core/platform/window.h"

class Win32_Window final : public IWindow
{
public:
    Win32_Window(const Window_Desc& ds = {});
    ~Win32_Window();

    Win32_Window(const Win32_Window&) = delete;
    Win32_Window(Win32_Window&&) = delete;
    
    fn operator=(const Win32_Window&) -> Win32_Window & = delete;
    fn operator=(Win32_Window&&) -> Win32_Window & = delete;
    
    fn handle() const -> void* override;
    fn show() const -> void override;
    fn present(bool vsync) const -> void override;
    
private:
    HWND m_handle = nullptr;
    
    #ifdef API_GL
    std::unique_ptr<Win32_GL_Context> m_gl_context = nullptr;
    #else
    struct Win32_No_Context {};
    std::unique_ptr<Win32_No_Context> m_no_context = nullptr; // @Note: To keep the class always of same size.
    #endif
};

#endif // PFM_WIN 