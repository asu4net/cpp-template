#pragma once

using Audio_Handle = Slot_Handle;

namespace Core
{
    auto audio_init() -> bool;
    auto audio_done() -> void;
    auto audio_load(const std::string& filename) -> Audio_Handle;
    auto audio_free(const Audio_Handle& handle) -> void;
    auto audio_play(const Audio_Handle& handle) -> void;
    auto audio_stop(const Audio_Handle& handle) -> void;
    auto set_volume(const Audio_Handle& handle, f32 volume) -> void;
}