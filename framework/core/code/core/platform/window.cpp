#include "window.h"

#if defined (PFM_WIN)
    #define WIN32_MEAN_AND_LEAN
    #include <Windows.h>
    #include "core/backend/win32/win32_window.h"
#endif

fn IWindow::create(const Window_Desc& ds) -> Ptr
{
#if defined(PFM_WIN)
    return std::make_shared<Win32_Window>(ds);
#else
    return nullptr;
#endif
}
