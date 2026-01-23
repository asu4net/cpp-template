#pragma once

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>

fn app_imgui_init_win32_gl(HWND hwnd, HDC hdc, HGLRC hglrc) -> void;
fn app_imgui_done_win32_gl() -> void;
fn app_imgui_begin_win32_gl() -> void;
fn app_imgui_end_win32_gl() -> void;