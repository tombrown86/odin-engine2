workspace "odin-engine2"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "(buildcfg)-(system)-(architecture)"

project "odin-engine2"
	location "odin-engine2"
	kind "SharedLib"
	language "C++"
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-intermediates/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/src/**.c"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "8.1"

		defines
		{
			"ODIN_PLATFORM_WINDOWS",
			"ODIN_BUILD_DLL",
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}
		
	filter "configurations:Debug"
		defines "ODIN_DEBUG"
		symbols "On"
		
	filter "configurations:Release"
		defines "ODIN_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "ODIN_DIST"
		optimize "On"



project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-intermediates/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/src/**.c"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include",
		"odin-engine2/src"
	}

	links 
	{
		"odin-engine2"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "8.1"

		defines
		{
			"ODIN_PLATFORM_WINDOWS"
		}

		
	filter "configurations:Debug"
		defines "ODIN_DEBUG"
		symbols "On"
		
	filter "configurations:Release"
		defines "ODIN_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "ODIN_DIST"
		optimize "On"

