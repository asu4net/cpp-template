#include "platform.h"

#if defined(CORE_DEBUG) && defined(CORE_GL)

#include "core/backend/opengl/gl_functions.h"

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
    core_log("[GL DEBUG] %s\n", message);
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
        auto operator=(const Platform_State&) -> Platform_State& = default;
        auto operator=(Platform_State&&) -> Platform_State& = default;

        // @Note: ....I just wanted to do this.
        ~Platform_State() { audio_done(); }

    } g_state;
    
    auto core_platform_init(Platform_Desc ds) -> bool
    {
        if (g_state.is_setup)
        g_state = {}; // @Note: Reset the state.

        set_working_dir(ds.working_dir);
        g_state.window = IWindow::create(ds.window);
        g_state.input = IInput::create(ds.input);
        ImGui::Init(*g_state.window);
        audio_init();
        g_state.is_setup = g_state.window && g_state.input; 
        
        #if defined(CORE_DEBUG) && defined(CORE_GL)
            glEnable(GL_DEBUG_OUTPUT);
            glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
            glDebugMessageCallback(_gl_debug_callback, nullptr);
        #endif

            //glBindTexture(GL_TEXTURE_2D, 999999); // @Note: Uncomment to check if the errors work.

        return g_state.is_setup;
    }

    auto core_swap_buffers(bool vsync) -> void
    {
        g_state.window->present(vsync);
    }

    auto core_poll_events() -> void
    {
        g_state.input->poll_events();
    }

    auto core_events_this_frame() -> const std::vector<Input_Event>&
    {
        return g_state.input->events_this_frame();
    }

    auto core_key_down(u32 key_code) -> bool
    {
        return g_state.input->key_down(key_code);
    }

    auto core_cursor_mode_set(Cursor_Mode mode) -> void
    {
        g_state.input->set_cursor_mode(mode);
    }

    auto core_time_step() -> void
    {
        g_state.time.step();
    }

    auto core_frame_time() -> f32
    {
        return g_state.time.frame_time();
    }

    auto core_frame_rate() -> f32
    {
        return g_state.time.frame_rate();
    }

    auto core_av_frame_rate() -> f32
    {
        return g_state.time.av_frame_rate();
    }

    auto core_time_scale_set(f32 scale) -> void
    {
        g_state.time.set_scale(scale);
    }
}

auto ImGui::ForceSaveIniFile() -> void
{

    ImGui::SaveIniSettingsToDisk(ImGui::GetIO().IniFilename); // @Note: Manually save the file.
    ImGui::GetIO().IniFilename = nullptr; // @Note: Prevent ImGui to save the file when it destroys the context.
}
