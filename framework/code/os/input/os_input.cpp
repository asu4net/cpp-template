#include "os_input.h"

#if defined (GAME_WIN)
    #define WIN32_MEAN_AND_LEAN
    #include <Windows.h>
    #include "os_win32_input.h"
#endif

auto IInput::create(const Input_Desc& ds) -> Ptr
{
#if defined(GAME_WIN)
    return std::make_unique<Win32_Input>(ds);
#else
    return nullptr;
#endif
}
