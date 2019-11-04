#pragma once

#include <memory>
#include "Core.h"
#include "spdlog\spdlog.h"
#include "spdlog\sinks\stdout_color_sinks.h"
#include "spdlog\spdlog.h"

namespace Odin {
	class ODIN_API Log
	{
		public:
			static void init();
			inline static std::shared_ptr<spdlog::logger> & GetCoreLogger() { return s_CoreLogger; }
			inline static std::shared_ptr<spdlog::logger> & GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define ODIN_CORE_ERROR(...) ::Odin::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ODIN_CORE_WARN(...) ::Odin::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ODIN_CORE_INFO(...) ::Odin::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ODIN_CORE_TRACE(...) ::Odin::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ODIN_CORE_FATAL(...) ::Odin::Log::GetCoreLogger()->fatal(__VA_ARGS__)
// Client log macros
#define ODIN_ERROR(...) ::Odin::Log::GetClientLogger()->error(__VA_ARGS__)
#define ODIN_WARN(...) ::Odin::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ODIN_INFO(...) ::Odin::Log::GetClientLogger()->info(__VA_ARGS__)
#define ODIN_TRACE(...) ::Odin::Log::GetClientLogger()->trace(__VA_ARGS__)
#define ODIN_FATAL(...) ::Odin::Log::GetClientLogger()->fatal(__VA_ARGS__)