#include "platform.h"

#if defined(CFG_DEBUG) && defined(API_GL)

#include "core/backend/opengl/gl_functions.h"

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
    LOG("[GL DEBUG] %s\n", message);
}

#endif

namespace Core
{
    struct Platform_State
    {
        bool is_setup = false;
        IWindow::Ptr window;
        IInput::Ptr input;
        Time time;

        // @Note: This is garbage, I hate C++....
        Platform_State() = default;
        Platform_State(const Platform_State&) = default;
        Platform_State(Platform_State&&) = default;
        fn operator=(const Platform_State&) -> Platform_State& = default;
        fn operator=(Platform_State&&) -> Platform_State& = default;

        // @Note: ....I just wanted to do this.
        ~Platform_State() { audio_done(); }

    } g_state;
    
    fn setup_platform(Platform_Desc ds) -> bool
    {
        if (g_state.is_setup)
        then g_state = {}; // @Note: Reset the state.

        set_working_dir(ds.working_dir);
        g_state.window = IWindow::create(ds.window);
        g_state.input = IInput::create(ds.input);
        ImGui::Init(*g_state.window);
        audio_init();
        g_state.is_setup = g_state.window && g_state.input; 
        
        #if defined(CFG_DEBUG) && defined(API_GL)
            glEnable(GL_DEBUG_OUTPUT);
            glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
            glDebugMessageCallback(_gl_debug_callback, nullptr);
        #endif

            //glBindTexture(GL_TEXTURE_2D, 999999); // @Note: Uncomment to check if the errors work.

        return g_state.is_setup;
    }

    fn swap_buffers(bool vsync) -> void
    {
        g_state.window->present(vsync);
    }

    fn poll_events() -> void
    {
        g_state.input->poll_events();
    }

    fn events_this_frame() -> const std::vector<Input_Event>&
    {
        return g_state.input->events_this_frame();
    }

    fn key_down(u32 key_code) -> bool
    {
        return g_state.input->key_down(key_code);
    }

    fn set_cursor_mode(Cursor_Mode mode) -> void
    {
        g_state.input->set_cursor_mode(mode);
    }

    fn time_step() -> void
    {
        g_state.time.step();
    }

    fn frame_time() -> f32
    {
        return g_state.time.frame_time();
    }

    fn frame_rate() -> f32
    {
        return g_state.time.frame_rate();
    }

    fn av_frame_rate() -> f32
    {
        return g_state.time.av_frame_rate();
    }

    fn set_time_scale(f32 scale) -> void
    {
        g_state.time.set_scale(scale);
    }
}

fn ImGui::ForceSaveIniFile() -> void
{

    ImGui::SaveIniSettingsToDisk(ImGui::GetIO().IniFilename); // @Note: Manually save the file.
    ImGui::GetIO().IniFilename = nullptr; // @Note: Prevent ImGui to save the file when it destroys the context.
}
