#pragma once
#include "core/platform/input.h"

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>


class Win32_Input final : public IInput
{
public:
    using Process_Events_Signature = LRESULT(*)(HWND, UINT, WPARAM, LPARAM);
    static fn CALLBACK process_events(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)->LRESULT;

    Win32_Input(const Input_Desc& ds = {});
    ~Win32_Input();

    Win32_Input(const Win32_Input&) = delete;
    Win32_Input(Win32_Input&&) = delete;

    fn operator=(const Win32_Input&) -> Win32_Input& = delete;
    fn operator=(Win32_Input&&) -> Win32_Input& = delete;

    fn poll_events() const -> void override;
    fn events_this_frame() const -> const std::vector<Input_Event>& override;
    fn key_down(u32 key_code) const -> bool override;
    fn set_cursor_mode(Cursor_Mode mode) -> void override;
};
