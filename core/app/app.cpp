#include "app.h"

#if defined(GAME_DEBUG) && defined(GAME_GL)

#include "os_gl.h"
#include "os_core.h"
#include "imgui.h"

// @Note: This is not in the GL context because it's platform independent. (I guess)

internal fn APIENTRY _gl_debug_callback(
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

internal fn app_time_step() -> void;

internal constexpr u32 FPS_SAMPLES = 30;

struct App_Time {
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
};

struct App {
    bool is_init = false;
    bool quit = false;
    App_Time time;
    // @Note: Os stuff (pending to remove OOP).
    IWindow::Ptr window;
    IInput::Ptr input;
} g_app;

fn app_init(App_Desc ds) -> bool {
    if (g_app.is_init) {
        app_done();
    }
    os_set_working_dir(ds.working_dir);
    g_app.input = IInput::create(ds.input);
    g_app.window = IWindow::create(ds.window);
    if (ds.init_imgui) {
        imgui_init(*g_app.window);
    }
    audio_init();
    g_app.is_init = g_app.window && g_app.input;

#if defined(GAME_DEBUG) && defined(GAME_GL)
    glEnable(GL_DEBUG_OUTPUT);
    glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
    glDebugMessageCallback(_gl_debug_callback, nullptr);
#endif

    //glBindTexture(GL_TEXTURE_2D, 999999); // @Note: Uncomment to check if the errors work.

    return g_app.is_init;
}

fn app_done() -> void {
    if (g_app.is_init) {
        audio_done();
        imgui_done();
        g_app.window.reset();
        g_app.input.reset();
        g_app = {};
    }
}

fn app_running() -> bool {
    // Process frame events.
    internal fn quit = []() {
        g_app.quit = true;
        if (imgui_is_init()) {
            imgui_force_save_ini();
        }
    };

    g_app.input->poll_events();
    app_time_step();

    for (const auto& event: app_events_this_frame()) {
        if (event.type == Input_Event::Quit) {
            quit();    
        }
        #if GAME_DEBUG
        if (event.key_code == Key_Code::Escape) {
            quit();
        }
        #endif      
    }
    return !g_app.quit;
}

fn app_swap_buffers(bool vsync) -> void {
    g_app.window->present(vsync);
}

fn app_events_this_frame() -> const std::vector<Input_Event>& {
    return g_app.input->events_this_frame();
}

fn app_key_down(u32 key_code) -> bool {
    return g_app.input->key_down(key_code);
}

fn app_set_cursor_mode(Cursor_Mode mode) -> void {
    g_app.input->set_cursor_mode(mode);
}

internal fn app_time_step() -> void {
    auto& time = g_app.time;

    //@Note: Lazy init.
    if (time.seconds < 0) {
        time.last_time = os_get_time();
        time.acc_fixed_frame_time = 0.f;
        time.seconds = 0;
    }

    f64 current_time = os_get_time();
    time.frame_count += 1;
    f64 time_between_frames = current_time - time.last_time;
    time.last_time = current_time;
    time.seconds += time_between_frames;
    
    f64 real_dt = std::clamp(time_between_frames, 0.0, time.max_frame_time);
    time.frame_time = (f32)(real_dt * time.scale);

    time.acc_fixed_frame_time += real_dt;
    
    while (time.acc_fixed_frame_time >= time.fixed_frame_time) {
        time.acc_fixed_frame_time -= time.fixed_frame_time;
        time.fixed_ticks += 1;
    }
    
    time.frame_total -= time.frame_times[time.frame_index];
    time.frame_times[time.frame_index] = time.frame_time;
    time.frame_total += time.frame_time;
    time.frame_index = (time.frame_index + 1) % FPS_SAMPLES;
}

fn app_frame_time() -> f32 {
    return g_app.time.frame_time;
}

fn app_frame_rate() -> f32 {
    f32 av = g_app.time.frame_total / FPS_SAMPLES;
    return av > 0.f ? 1.f / av : 0.f;
}

fn app_av_frame_rate() -> f32 {
    return (f32) g_app.time.frame_count / (f32) g_app.time.seconds;
}

fn app_set_time_scale(f32 scale) -> void {
    g_app.time.scale = scale;
}