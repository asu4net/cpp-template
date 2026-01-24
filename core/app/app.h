
#pragma once
#include "os_window.h"
#include "os_input.h"
#include "audio.h"
#include "imgui_state.h"
#include "time_state.h"

// @Note: This file is just a C-style easy wrapper for the common stuff. You don't need to use it.

struct App_Desc
{
    std::string working_dir = ".\\assets";
    Window_Desc window;
    Input_Desc input;

#ifdef GAME_DEBUG
    bool init_imgui = true;
#else 
    bool init_imgui = false;
#endif
};

// *** Setup ***

// @Note: Just creates IWindow and IInput instances.
fn app_init(App_Desc ds = {}) -> bool;
fn app_done() -> void;
fn app_running() -> bool;

// *** Window ***
fn app_swap_buffers(bool vsync = true) -> void;

// *** Input ***

fn app_events_this_frame() -> const std::vector<Input_Event>&;
fn app_key_down(u32 key_code) -> bool;
fn app_set_cursor_mode(Cursor_Mode mode) -> void;