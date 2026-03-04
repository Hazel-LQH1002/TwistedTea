#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
namespace Twist
{
	class TWIST_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};
}


// Core Log Macros
#define TW_CORE_TRACE(...)		::Twist::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define TW_CORE_INFO(...)		::Twist::Log::GetCoreLogger()->info(__VA_ARGS__)
#define TW_CORE_WARN(...)		::Twist::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define TW_CORE_ERROR(...)		::Twist::Log::GetCoreLogger()->error(__VA_ARGS__)
#define TW_CORE_FATAL(...)		::Twist::Log::GetCoreLogger()->fatal(__VA_ARGS__)


// Client Log Macros
#define TW_TRACE(...)		::Twist::Log::GetClientLogger()->trace(__VA_ARGS__)
#define TW_INFO(...)		::Twist::Log::GetClientLogger()->info(__VA_ARGS__)
#define TW_WARN(...)		::Twist::Log::GetClientLogger()->warn(__VA_ARGS__)
#define TW_ERROR(...)		::Twist::Log::GetClientLogger()->error(__VA_ARGS__)
#define TW_FATAL(...)		::Twist::Log::GetClientLogger()->fatal(__VA_ARGS__)