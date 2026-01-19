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
    fn setup_platform(Platform_Desc ds = {}) -> bool;

    // *** Window ***
    fn swap_buffers(bool vsync = true) -> void;

    // *** Input ***

    fn poll_events() -> void;
    fn events_this_frame() -> const std::vector<Input_Event>&;
    fn key_down(u32 key_code) -> bool;
    fn set_cursor_mode(Cursor_Mode mode) -> void;

    // *** Time ***

    fn time_step() -> void;
    fn frame_time() -> f32;
    fn frame_rate() -> f32;
    fn av_frame_rate() -> f32;
    fn set_time_scale(f32 scale) -> void;
}

// *** ImGui ***
namespace ImGui
{
    // @Hack: We have to do this before ImGui::DestroyContext.
    // Why? Because when we reach DestoyContext ImGui have already zeroed the window positions.
    // Why? No fucking clue.
    fn ForceSaveIniFile() -> void;
}
