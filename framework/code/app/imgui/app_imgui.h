#pragma once

#include "core_window.h"

auto app_imgui_init(const IWindow& window) -> void;
auto app_imgui_done() -> void;
auto app_imgui_begin() -> void;
auto app_imgui_end() -> void;