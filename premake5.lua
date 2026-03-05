workspace "Twist"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	filter "system:windows"
		buildoptions {"/utf-8"}
	
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Twist/vendor/GLFW/include"

include "Twist/vendor/GLFW"

project "Twist"
	location "Twist"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "twpch.h"
	pchsource "Twist/src/twpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "on"
		systemversion "10.0"

		defines
		{
			"TW_PLATFORM_WINDOWS", 
			"TW_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/DumbGame")
		}

	filter "configurations:Debug"
		defines "TW_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "TW_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "TW_DIST"
		optimize "On"


project "DumbGame"
	location "DumbGame"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"Twist/vendor/spdlog/include",
		"Twist/src"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "on"
		systemversion "10.0"

		defines
		{
			"TW_PLATFORM_WINDOWS" 
		}

	links
	{
		"Twist"
	}

	filter "configurations:Debug"
		defines "TW_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "TW_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "TW_DIST"
		optimize "On"