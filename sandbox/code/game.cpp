#include "os_gl.h"

fn main(i32 argc, cstring* argv) -> i32 {
    dbg_log("Hellope!");
    app_init();

    bool quit = false;

    while (!quit) {
        app_poll_events();
        
        for (const auto& event: app_events_this_frame()) {
            if (event.type == Input_Event::Quit) {
                quit = true;
                app_imgui_force_save_ini();
            }
            if (event.key_code == Key_Code::Escape) {
                quit = true;
            }
        }

        glClear(GL_COLOR_BUFFER_BIT);
        app_imgui_begin();
        ImGui::Begin("Hi");
        ImGui::End();
        app_imgui_end();

        app_swap_buffers();
    }

    app_done();
    return 0;
}