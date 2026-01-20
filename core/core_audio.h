#pragma once

using Audio_Handle = Slot_Handle;

auto core_audio_init() -> bool;
auto core_audio_done() -> void;
auto core_audio_load(const std::string& filename) -> Audio_Handle;
auto core_audio_free(const Audio_Handle& handle) -> void;
auto core_audio_play(const Audio_Handle& handle) -> void;
auto core_audio_stop(const Audio_Handle& handle) -> void;
auto core_audio_volume_set(const Audio_Handle& handle, f32 volume) -> void;