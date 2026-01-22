#pragma once

auto app_imgui_init(const class IWindow& window) -> void;
auto app_imgui_done() -> void;
auto app_imgui_begin() -> void;
auto app_imgui_end() -> void;

// @Hack: We have to do this before ImGui::DestroyContext.
// Why? Because when we reach DestoyContext ImGui have already zeroed the window positions.
// Why? No fucking clue.
auto app_imgui_force_save_ini() -> void;