cpp_lib_project "imgui"
    includedirs { "src" }
    files { "src/**.h", "src/**.cpp" }
    
    -- @Pending: Check graphics API.
    -- @Note: Backends
    removefiles { "src/backends/**" }
    
    filter "system:windows"
        files 
        { 
            "src/backends/imgui_impl_opengl3_loader.h", 
            "src/backends/imgui_impl_opengl3.h", 
            "src/backends/imgui_impl_opengl3.cpp", 
            "src/backends/imgui_impl_win32.h", 
            "src/backends/imgui_impl_win32.cpp" 
        }
    filter{}
    
    config_base()