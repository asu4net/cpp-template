#include "app.h"
#include "m_imgui.h"
#include "os_gl.h"

fn main() -> i32 {
    dbg_log("Hellope!");
    app_init();
    
    glClearColor(Color.Corn_Flower_Blue);

    while (app_running()) {
        
        glClear(GL_COLOR_BUFFER_BIT);
        
        internal fn imgui_frame = [] {
            using namespace ImGui;
            SetNextWindowSize({ 300, 270 }, ImGuiCond_FirstUseEver);
            Begin("Debug Screen");
            Text("FPS: %.2f", time_av_fps());
            End();
        };
        
        imgui_draw_frame(imgui_frame);
        os_swap_buffers();
    }
    
    app_done();
}
