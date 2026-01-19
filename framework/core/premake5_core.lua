core_location = "%{wks.location}/framework/core" 
core_code_location = core_location .. "/code"

function use_core()
    
    includedirs 
    { 
        core_code_location
    }
    
    files 
    { 
        core_location .. "/**.lua",
        core_code_location .. "/**.h", 
        core_code_location .. "/**.cpp", 
    }
end