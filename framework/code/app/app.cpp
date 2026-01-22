#include "app.h"

#if defined(GAME_DEBUG) && defined(GAME_GL)

#include "core_backend/gl_functions.h"
#include "os_core.h"
#include "core_imgui_state.h"
#include "imgui.h"

// @Note: This is not in the GL context because it's platform independent. (I guess)

static auto APIENTRY _gl_debug_callback(
    GLenum source, 
    GLenum type, 
    GLuint id, 
    GLenum severity, 
    GLsizei length, 
    const GLchar* message, 
    const void* userParam
) -> void
{
    dbg_log("[GL DEBUG] %s", message);
}

#endif

internal constexpr u32 FPS_SAMPLES = 240;

struct App
{
    bool is_setup = false;
    IWindow::Ptr window;
    IInput::Ptr input;

    f64 max_frame_time = 0.06;
    f64 fixed_frame_time = 0.06;
    f64 seconds = -1.f;
    f32 frame_time = 0.f;
    u32 frame_count = 0u;
    f64 acc_fixed_frame_time = 0.f;
    f64 last_time = 0.f;
    u32 fixed_ticks = 0u;
    f32 scale = 1.f;
    f32 frame_times[FPS_SAMPLES] = {};
    u32 frame_index = 0u;
    f32 frame_total = 0.f;

    // @Note: This is garbage, I hate C++....
    App() = default;
    App(const App&) = default;
    App(App&&) = default;
    auto operator=(const App&) -> App & = default;
    auto operator=(App&&) -> App & = default;

    // @Note: ....I just wanted to do this.
    ~App() { audio_done(); }

} g_app;

auto app_init(App_Desc ds) -> bool
{
    if (g_app.is_setup)
        g_app = {}; // @Note: Reset the state.

    os_set_working_dir(ds.working_dir);
    g_app.window = IWindow::create(ds.window);
    g_app.input = IInput::create(ds.input);
    ImGui::Init(*g_app.window);
    audio_init();
    g_app.is_setup = g_app.window && g_app.input;

#if defined(GAME_DEBUG) && defined(GAME_GL)
    glEnable(GL_DEBUG_OUTPUT);
    glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
    glDebugMessageCallback(_gl_debug_callback, nullptr);
#endif

    //glBindTexture(GL_TEXTURE_2D, 999999); // @Note: Uncomment to check if the errors work.

    return g_app.is_setup;
}

auto app_swap_buffers(bool vsync) -> void
{
    g_app.window->present(vsync);
}

auto app_poll_events() -> void
{
    g_app.input->poll_events();
}

auto app_events_this_frame() -> const std::vector<Input_Event>&
{
    return g_app.input->events_this_frame();
}

auto app_key_down(u32 key_code) -> bool
{
    return g_app.input->key_down(key_code);
}

auto app_set_cursor_mode(Cursor_Mode mode) -> void
{
    g_app.input->set_cursor_mode(mode);
}

auto ImGui::ForceSaveIniFile() -> void
{

    ImGui::SaveIniSettingsToDisk(ImGui::GetIO().IniFilename); // @Note: Manually save the file.
    ImGui::GetIO().IniFilename = nullptr; // @Note: Prevent ImGui to save the file when it destroys the context.
}

auto app_time_step() -> void
{
    //@Note: Lazy init.
    if (g_app.seconds < 0) 
    {
        g_app.last_time = os_get_time();
        g_app.acc_fixed_frame_time = g_app.fixed_frame_time;
        g_app.seconds = 0;
    }

    f64 current_time = os_get_time();
    g_app.frame_count += 1;
    f64 time_between_frames = current_time - g_app.last_time;
    g_app.last_time = current_time;
    g_app.seconds += time_between_frames;
    g_app.frame_time = (f32) std::clamp(time_between_frames, 0.0, g_app.max_frame_time) * g_app.scale;
    g_app.acc_fixed_frame_time += g_app.frame_time;

    while (g_app.acc_fixed_frame_time >= g_app.fixed_frame_time)
    {
        g_app.acc_fixed_frame_time -= g_app.fixed_frame_time;
        g_app.fixed_ticks += 1;
    }

    g_app.frame_total -= g_app.frame_times[g_app.frame_index];
    g_app.frame_times[g_app.frame_index] = g_app.frame_time;
    g_app.frame_total += g_app.frame_time;
    g_app.frame_index = (g_app.frame_index + 1) % FPS_SAMPLES;
}

auto app_frame_time() -> f32
{
    return g_app.frame_time;
}

auto app_frame_rate() -> f32
{
    f32 av = g_app.frame_total / FPS_SAMPLES;
    return av > 0.f ? 1.f / av : 0.f;
}

auto app_av_frame_rate() -> f32
{
    return (f32) g_app.frame_count / (f32) g_app.seconds;
}

auto app_set_time_scale(f32 scale) -> void
{
    g_app.scale = scale;
}