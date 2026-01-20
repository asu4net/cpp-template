#include "input.h"

#if defined (PFM_WIN)
    #define WIN32_MEAN_AND_LEAN
    #include <Windows.h>
    #include "core/backend/win32/win32_input.h"
#endif

auto IInput::create(const Input_Desc& ds) -> Ptr
{
#if defined(PFM_WIN)
    return std::make_unique<Win32_Input>(ds);
#else
    return nullptr;
#endif
}
