
#pragma once
#include "core_window.h"
#include "core_input.h"
#include "audio.h"
#include "app_imgui.h"

// @Note: This file is just a C-style easy wrapper for the common stuff. You don't need to use it.

struct App_Desc
{
    std::string working_dir = "\\..\\..\\assets";
    Window_Desc window;
    Input_Desc input;
};

// *** Setup ***

// @Note: Just creates IWindow and IInput instances.
auto app_init(App_Desc ds = {}) -> bool;

// *** Window ***
auto app_swap_buffers(bool vsync = true) -> void;

// *** Input ***

auto app_poll_events() -> void;
auto app_events_this_frame() -> const std::vector<Input_Event>&;
auto app_key_down(u32 key_code) -> bool;
auto app_set_cursor_mode(Cursor_Mode mode) -> void;

// *** Time ***

auto app_time_step() -> void;
auto app_frame_time() -> f32;
auto app_frame_rate() -> f32;
auto app_av_frame_rate() -> f32;
auto app_set_time_scale(f32 scale) -> void;

// *** ImGui ***
namespace ImGui
{
    // @Hack: We have to do this before ImGui::DestroyContext.
    // Why? Because when we reach DestoyContext ImGui have already zeroed the window positions.
    // Why? No fucking clue.
    auto ForceSaveIniFile() -> void;
}