fn main(i32 argc, cstring* argv) -> i32 {
    dbg_log("Hellope!");
    app_init();
    
    while (app_running()) {
        
        glClear(GL_COLOR_BUFFER_BIT);

        #if GAME_DEBUG
        imgui_frame_init();
        {
            ImGui::SetNextWindowSize({ 300, 270 }, ImGuiCond_FirstUseEver);
            ImGui::Begin("Debug Screen");
            ImGui::Text("FPS: %.2f", time_av_fps());
            ImGui::End();
        }
        imgui_frame_done();
        #endif
        
        os_swap_buffers();
    }
    
    app_done();
    return 0;
}
