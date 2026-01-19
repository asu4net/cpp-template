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

function use_imgui()
    includedirs 
    { 
        "%{wks.location}/3rd/imgui/src", 
        "%{wks.location}/3rd/imgui/src/backends"
    }
end

function link_imgui()

    links { "imgui" }
    
    defines
    {
        "_CRT_SECURE_NO_WARNINGS",
        "_SILENCE_CXX23_ALIGNED_STORAGE_DEPRECATION_WARNING"
    }

end