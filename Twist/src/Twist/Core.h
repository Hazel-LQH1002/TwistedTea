#pragma once

#ifdef TW_PLATFORM_WINDOWS
	#ifdef TW_BUILD_DLL
		#define TWIST_API __declspec(dllexport)
	#else
		#define TWIST_API __declspec(dllimport)
	#endif
#else
	#error Twist only supports Windows!
#endif

#define BIT(x) (1 << x)
