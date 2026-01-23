#pragma once

fn app_imgui_init(const class IWindow& window) -> void;
fn app_imgui_done() -> void;
fn app_imgui_begin() -> void;
fn app_imgui_end() -> void;

// @Hack: We have to do this before ImGui::DestroyContext.
// Why? Because when we reach DestoyContext ImGui have already zeroed the window positions.
// Why? No fucking clue.
fn app_imgui_force_save_ini() -> void;