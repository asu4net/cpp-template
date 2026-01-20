core_location = "%{wks.location}/core" 

function use_core()
    
    includedirs 
    { 
        core_location
    }
    
    files 
    { 
        core_location .. "/**.lua",
        core_location .. "/**.h", 
        core_location .. "/**.cpp", 
    }
end