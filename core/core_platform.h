#pragma once
#include "core_window.h"
#include "core_input.h"
#include "core_time.h"
#include "core_imgui_state.h"

// @Note: This file is just a C-style easy wrapper for the common stuff. You don't need to use it.

struct Platform_Desc
{
    std::string working_dir = "\\..\\..\\assets";
    Window_Desc window;
    Input_Desc input;
};

// *** Setup ***

// @Note: Just creates IWindow and IInput instances.
auto core_platform_init(Platform_Desc ds = {}) -> bool;

// *** Window ***
auto core_swap_buffers(bool vsync = true) -> void;

// *** Input ***

auto core_poll_events() -> void;
auto core_events_this_frame() -> const std::vector<Input_Event>&;
auto core_key_down(u32 key_code) -> bool;
auto core_cursor_mode_set(Cursor_Mode mode) -> void;

// *** Time ***

auto core_time_step() -> void;
auto core_frame_time() -> f32;
auto core_frame_rate() -> f32;
auto core_av_frame_rate() -> f32;
auto core_time_scale_set(f32 scale) -> void;

// *** ImGui ***
namespace ImGui
{
    // @Hack: We have to do this before ImGui::DestroyContext.
    // Why? Because when we reach DestoyContext ImGui have already zeroed the window positions.
    // Why? No fucking clue.
    auto ForceSaveIniFile() -> void;
}