framework_location = "%{wks.location}/framework/code" 
imgui_location = "%{wks.location}/framework/3rd/imgui/src" 

cpp_lib_project "framework"
    --- @Note: PCH config
    pchheader ("pch.h")
    pchsource ("code/pch.cpp")
    forceincludes ("pch.h")
    ---
    includedirs 
    {
        "3rd/imgui/src", 
        "3rd/imgui/src/backends",
        "3rd/miniaudio",
        "3rd/khr",
        "3rd/stb",
        "3rd/tiny_obj_loader",
        "code",
        "code/base",
        "code/app",
        "code/dbg",
        "code/load",
        "code/audio",
        "code/os",
        "code/os/core",
        "code/os/core/win",
        "code/core_backend",
        "code/core_vendor",         
    }
    
    files 
    {
        "3rd/miniaudio/**.h", 
        "3rd/khr/**.h", 
        "3rd/stb/**.h", 
        "3rd/tiny_obj_loader/**.h", 
        "code/**.h", 
        "code/**.cpp", 
        "framework_generate.lua" 
    }
    
    config_base()
    defines_backend()

function use_framework()
    
    includedirs 
    { 
        framework_location,
        imgui_location,
        imgui_location .. "/backends",
    }
    
    files 
    { 
        framework_location .. "/**.lua",
        framework_location .. "/**.h", 
        framework_location .. "/**.cpp", 
    }
end

function link_framework()

    links { "imgui" }
    
    defines
    {
        "_CRT_SECURE_NO_WARNINGS",
        "_SILENCE_CXX23_ALIGNED_STORAGE_DEPRECATION_WARNING"
    }
    
end