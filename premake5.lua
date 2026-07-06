workspace "LonEngine"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "LonEngine"
    location "LonEngine"
    kind "SharedLib"
    language "C++"

    targetdir("bin/" .. outputdir .. "/%{prj.name}" )
    objdir("bin-int/" .. outputdir .. "/%{prj.name}" )
    pchheader "lepch.h"
    pchsource "LonEngine/src/lepch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }
    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include"
    }
    buildoptions "/utf-8"

    filter "system:windows"
        cppdialect "c++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "LE_Platform_Windows",
            "LE_BUILD_DLL"
        }
        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" ..outputdir.. "/Sandbox")
        }
    filter "configuration.Debug"
        defines "LE_DEBUG"
        symbols "On"
    filter "configuration.Release"
        defines "LE_RELEASE"
        optimize "On"
    filter "configuration.Dist"
        defines "LE_DIST"
        optimize "On"
    
project "Sandbox"
        location "Sandbox"
        kind "ConsoleApp"
        language "C++"

    targetdir("bin/" .. outputdir .. "/%{prj.name}" )
    objdir("bin-int/" .. outputdir .. "/%{prj.name}" )

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }
    includedirs
    {
        "LonEngine/vendor/spdlog/include",
        "LonEngine/src"
    }
    links
    {
        "LonEngine"
    }
    buildoptions "/utf-8"
    filter "system:windows"
        cppdialect "c++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "LE_Platform_Windows"
        }

    filter "configuration.Debug"
        defines "LE_DEBUG"
        symbols "On"
    filter "configuration.Release"
        defines "LE_RELEASE"
        optimize "On"
    filter "configuration.Dist"
        defines "LE_DIST"
        optimize "On"
    