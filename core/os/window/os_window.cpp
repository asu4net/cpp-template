#include "os_window.h"

#if defined (GAME_WIN)
    #define WIN32_MEAN_AND_LEAN
    #include <Windows.h>
    #include "os_win32_window.h"
#endif

auto IWindow::create(const Window_Desc& ds) -> Ptr
{
#if defined(GAME_WIN)
    return std::make_shared<Win32_Window>(ds);
#else
    return nullptr;
#endif
}
