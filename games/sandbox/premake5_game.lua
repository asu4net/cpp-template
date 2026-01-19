cpp_app_project "sandbox"
    --- @Note: PCH config
    pchheader ("pch.h")
    pchsource ("code/pch.cpp")
    forceincludes ("pch.h")
    ---
    includedirs { "code" }
    files { "code/**.h", "code/**.cpp", "**.lua" }

    config_game()