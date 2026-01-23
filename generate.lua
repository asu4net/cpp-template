Render_Backend = {
    D3D11 = "GAME_D3D11",
    GL = "GAME_GL"
}

--------- GLOBAL VARIABLES ---------

render_backend    = Render_Backend.GL
cpp_version       = "C++17"
binaries_dir      = "%{wks.location}/../.bin/%{prj.name}/%{cfg.buildcfg}"
intermediates_dir = "%{wks.location}/../.bin-int/%{prj.name}/%{cfg.buildcfg}"

--------- BACKEND UTILITIES ---------

function is_windows()
    return package.config:sub(1,1) == '\\'
end

function defines_backend()
    filter {}
    defines { render_backend }
    if not is_windows() and render_backend == Render_Backend.D3D11 then
        undefines { render_backend }
        print("Dude, d3d11 is just for windows.")
    end
end

function link_backend()
    filter "system:windows"
        links { "User32.lib" }
    filter {}
    if is_windows() and render_backend == Render_Backend.D3D11 then
        filter "system:windows"
            links { "d3d11.lib" }
        elseif  render_backend == Render_Backend.GL then
            links { "OpenGL32.lib" }
        end
    filter {}
end

--------- PROJECT UTILITIES ---------

function cpp_project(name)
    project(name)
    language "C++"
    cppdialect (cpp_version)
    targetdir (binaries_dir)
    objdir (intermediates_dir)
    debugdir ("%{wks.location}/" .. name)
    
    -- @Note: Named PCH approach.
    -- if use_pch ~= false then
    --    local pch = name .. "_pch"
    --    pchheader (pch .. ".h")
    --    pchsource (pch_dir .. pch .. ".cpp")
    --    forceincludes (pch .. ".h")
    
end

function cpp_lib_project(name)
    cpp_project(name)
    kind "StaticLib"
end

function cpp_app_project(name)
    cpp_project(name)
    filter "configurations:dist"
        kind "WindowedApp"
        entrypoint "mainCRTStartup"
    filter "configurations:debug or configurations:release"
        kind "ConsoleApp"
    filter {}
end

function config_base()

    filter "configurations:debug"
        runtime  "Debug"
        symbols  "On"
        optimize "Off"
        defines  "GAME_DEBUG"

    filter "configurations:release"
        runtime  "Release"
        symbols  "On"
        optimize "On"
        defines  "GAME_RELEASE"

    filter "configurations:dist"
        runtime  "Release"
        symbols  "Off"
        optimize "On"
        defines  "GAME_DIST"

    filter "system:windows"
        defines "GAME_WIN"
end

-------------------------------------------------

--    @Pending: We would need to do something like this in the future, for both core and graphics.
--
--    filter {}
--
--    -- First remove all backend files
--    removefiles { "src/core/backend/**.h", "src/core/backend/**.cpp" }
--
--    -- Then add render backend files
--    if render_backend == Render_Backend.D3D11 then
--        files { "src/core/backend/d3d11/**.h", "src/core/backend/d3d11/**.cpp" }
--    elseif render_backend == Render_Backend.GL then
--        files { "src/core/backend/opengl/**.h", "src/core/backend/opengl/**.cpp" }
--    end
--
--    -- Also add platform specific files 
--    filter "system:windows"
--        files { "src/core/backend/win32/**.h", "src/core/backend/win32/**.cpp" }
--    filter {}
-- end

--------- WORKSPACE ---------

workspace "cpp-template"
    location ".project-files"
    architecture "x64"
    configurations { "debug", "release", "dist" }
    startproject "sandbox"

group "3rd"
    include "3rd/imgui/imgui_generate.lua"
group ""

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
    pchsource ("core/core_pch.cpp")
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

function config_game()
    
    files { "assets/**.glsl" }    

    use_core()
    
    config_base()
    defines_backend()

    link_backend()
    link_core()

end

include "sandbox/sandbox_generate.lua"