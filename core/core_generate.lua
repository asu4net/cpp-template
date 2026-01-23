core_location = "%{wks.location}/../core/code" 
imgui_location = core_location .. "/../3rd/imgui/src" 
imgui_backends_location = core_location .. "/../3rd/imgui/src/backends" 

core_includedirs = {
    imgui_location,
    imgui_backends_location,
    core_location,
    core_location .. "/**",
    core_location .. "/../3rd/khr",
}

cpp_lib_project "core"
    --- @Note: PCH config
    pchheader ("core_pch.h")
    pchsource ("code/core_pch.cpp")
    forceincludes ("core_pch.h")
    ---
    includedirs 
    {
        "3rd/miniaudio",
        "3rd/stb",
        "3rd/tiny_obj_loader",
        core_includedirs,
    }
    
    files 
    {
        "3rd/miniaudio/**.h", 
        "3rd/khr/**.h", 
        "3rd/stb/**.h", 
        "3rd/tiny_obj_loader/**.h", 
        "code/**.h", 
        "code/**.cpp", 
        "core_generate.lua" 
    }
    
    config_base()
    defines_backend()

function use_core()
    
    includedirs 
    { 
        core_includedirs,
        imgui_location,
        imgui_backends_location,
    }
end

function link_core()

    links { "core", "imgui" }
    
    defines
    {
        "_CRT_SECURE_NO_WARNINGS",
        "_SILENCE_CXX23_ALIGNED_STORAGE_DEPRECATION_WARNING"
    }
    
end