loc_core = "%{wks.location}/../core/" 
loc_3rd = "%{wks.location}/../3rd/"

core_includedirs = {
    loc_3rd .. "miniaudio",
    loc_3rd .. "tiny_obj_loader",
    loc_3rd .. "khr",
    loc_3rd .. "stb",
    loc_3rd .. "imgui/src/",
    loc_3rd .. "imgui/src/backends/", 
    loc_core,
    loc_core .. "**",
}

cpp_lib_project "core"
    pchheader ("core_pch.h")
    pchsource ("core_pch.cpp")
    forceincludes ("core_pch.h")
    includedirs(core_includedirs)
    
    files 
    {
        loc_3rd .. "miniaudio/**.h", 
        loc_3rd .. "tiny_obj_loader/**.h", 
        loc_3rd .. "khr/**.h", 
        loc_3rd .. "stb/**.h", 
        loc_core .. "/**.h",
        loc_core .. "/**.cpp",
    }
    
    config_base()
    defines_backend()

function use_core()
    includedirs(core_includedirs)
end

function link_core()
    links { "core", "imgui" }
    defines
    {
        "_CRT_SECURE_NO_WARNINGS",
        "_SILENCE_CXX23_ALIGNED_STORAGE_DEPRECATION_WARNING"
    }
end