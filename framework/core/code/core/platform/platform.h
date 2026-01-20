#pragma once
#include "core/platform/window.h"
#include "core/platform/input.h"
#include "core/platform/time.h"
#include "core/imgui/imgui_state.h"

// @Note: This file is just a C-style easy wrapper for the common stuff. You don't need to use it.

struct Platform_Desc
{
    std::string working_dir = "\\..\\..\\assets";
    Window_Desc window;
    Input_Desc input;
};

namespace Core
{
    // *** Setup ***

    // @Note: Just creates IWindow and IInput instances.
    auto setup_platform(Platform_Desc ds = {}) -> bool;

    // *** Window ***
    auto swap_buffers(bool vsync = true) -> void;

    // *** Input ***

    auto poll_events() -> void;
    auto events_this_frame() -> const std::vector<Input_Event>&;
    auto key_down(u32 key_code) -> bool;
    auto set_cursor_mode(Cursor_Mode mode) -> void;

    // *** Time ***

    auto time_step() -> void;
    auto frame_time() -> f32;
    auto frame_rate() -> f32;
    auto av_frame_rate() -> f32;
    auto set_time_scale(f32 scale) -> void;
}

// *** ImGui ***
namespace ImGui
{
    // @Hack: We have to do this before ImGui::DestroyContext.
    // Why? Because when we reach DestoyContext ImGui have already zeroed the window positions.
    // Why? No fucking clue.
    auto ForceSaveIniFile() -> void;
}
