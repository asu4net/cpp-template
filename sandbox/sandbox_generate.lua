cpp_app_project "sandbox"
    
    debugdir("%{wks.location}/../sandbox")

    --- @Note: PCH config
    pchheader ("pch.h")
    pchsource ("code/pch.cpp")
    forceincludes ("pch.h")
    ---
    includedirs { "code" }
    files { "code/**.h", "code/**.cpp", "**.lua" }

    config_game()