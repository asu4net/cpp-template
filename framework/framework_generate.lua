framework_location = "%{wks.location}/../framework/code" 
imgui_location = framework_location .. "/../3rd/imgui/src" 
imgui_backends_location = framework_location .. "/../3rd/imgui/src/backends" 

framework_includedirs = {
    framework_location,
    imgui_location,
    imgui_backends_location,
    framework_location .. "/../3rd/khr",
    framework_location .. "/base",
    framework_location .. "/app",
    framework_location .. "/app/imgui",
    framework_location .. "/app/imgui/win-gl",
    framework_location .. "/dbg",
    framework_location .. "/load",
    framework_location .. "/audio",
    framework_location .. "/os",
    framework_location .. "/os/gl",
    framework_location .. "/os/core",
    framework_location .. "/os/core/win",
    framework_location .. "/os/window",
    framework_location .. "/os/window/win",
    framework_location .. "/os/window/win-gl",
    framework_location .. "/os/input",
    framework_location .. "/os/input/win",
}

cpp_lib_project "framework"
    --- @Note: PCH config
    pchheader ("framework_pch.h")
    pchsource ("code/framework_pch.cpp")
    forceincludes ("framework_pch.h")
    ---
    includedirs 
    {
        "3rd/miniaudio",
        "3rd/stb",
        "3rd/tiny_obj_loader",
        framework_includedirs,
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
        framework_includedirs,
        imgui_location,
        imgui_backends_location,
    }
end

function link_framework()

    links { "framework", "imgui" }
    
    defines
    {
        "_CRT_SECURE_NO_WARNINGS",
        "_SILENCE_CXX23_ALIGNED_STORAGE_DEPRECATION_WARNING"
    }
    
end