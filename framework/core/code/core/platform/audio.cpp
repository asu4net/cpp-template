#include "audio.h"

#define MINIAUDIO_IMPLEMENTATION
#include "vendor/miniaudio.h"

struct Audio_State
{
    ma_engine engine;
    Slot_Map<ma_sound> sounds;
    bool inited = false;
};

static Audio_State g_audio;

auto core_audio_init() -> bool
{
    if (g_audio.inited)
    {
        core_audio_done();
    }

    core_log("Audio System created!\n");
    auto result = ma_engine_init(nullptr, &g_audio.engine);
    if (result != MA_SUCCESS) 
    {
        core_check(false, "Error! Failed to initialize the audio engine!");
        return false;
    }
    g_audio.inited = true;
    return true;
}

auto core_audio_done() -> void
{
    if (g_audio.inited)
    {
        core_log("Audio System destroyed!\n");
        ma_engine_uninit(&g_audio.engine);
        g_audio.inited = false;
    }
}

auto core_audio_load(const std::string& filename) -> Audio_Handle
{
    auto&[handle, sound] = g_audio.sounds.insert();
    auto result = ma_sound_init_from_file(&g_audio.engine, filename.c_str(), 0, nullptr, nullptr, sound);
    if (result != MA_SUCCESS)
    {
        core_check(false, "Error! Failed to load the sound!");
        return {};
    }
    return handle;
}

auto core_audio_free(const Audio_Handle& handle) -> void
{
    auto* sound = g_audio.sounds.get(handle);
    if (sound)
    ma_sound_uninit(sound);
}

auto core_audio_play(const Audio_Handle& handle) -> void
{
    auto* sound = g_audio.sounds.get(handle);
    if (sound)
    ma_sound_start(sound);
}

auto core_audio_stop(const Audio_Handle& handle) -> void
{
    auto* sound = g_audio.sounds.get(handle);
    if (sound)
    ma_sound_stop(sound);
}

auto core_audio_volume_set(const Audio_Handle& handle, f32 volume) -> void
{
    auto* sound = g_audio.sounds.get(handle);
    if (sound)
    ma_sound_set_volume(sound, volume);
}