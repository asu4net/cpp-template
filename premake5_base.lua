Render_Backend = {
    D3D11 = "API_D3D11",
    GL = "API_GL"
}

--------- GLOBAL VARIABLES ---------

render_backend    = Render_Backend.GL
cpp_version       = "C++17"
binaries_dir      = "%{prj.location}/bin/%{cfg.buildcfg}"
intermediates_dir = "%{prj.location}/bin-int/%{cfg.buildcfg}"

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
        defines  "CFG_DEBUG"

    filter "configurations:release"
        runtime  "Release"
        symbols  "On"
        optimize "On"
        defines  "CFG_RELEASE"

    filter "configurations:dist"
        runtime  "Release"
        symbols  "Off"
        optimize "On"
        defines  "CFG_DIST"
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