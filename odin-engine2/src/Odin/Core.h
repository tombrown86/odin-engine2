#pragma once

#ifdef ODIN_PLATFORM_WINDOWS
	#ifdef ODIN_BUILD_DLL
		#define ODIN_API __declspec(dllexport)
	#else
		#define ODIN_API __declspec(dllimport)
	#endif
#else
	#error Windows only, sorry
#endif
