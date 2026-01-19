include "premake5_base.lua"

workspace "cpp-game-framework"
    architecture "x64"
    configurations { "debug", "release", "dist" }
    startproject "sandbox"

group "3rd"
    include "3rd/imgui/premake5_imgui.lua"
group ""

-- @Note: Our framework is just a bunch folders with the shared code.
include "framework/core/premake5_core.lua"

function config_game()
    files { "assets/**.glsl" }    

    use_imgui() 
    use_core()
    
    config_base()
    defines_backend()

    link_backend()
    link_imgui()
end

group "games"
    include "games/sandbox/premake5_game.lua"
group ""