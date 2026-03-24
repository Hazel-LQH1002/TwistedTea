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

#ifdef TW_ENABLE_ASSERTS
#define TW_ASSERT(x, ...) { if(!(x)) { TW_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define TW_CORE_ASSERT(x, ...) { if(!(x)) { TW _CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#define TW_ASSERT(x, ...)
#define TW_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)
