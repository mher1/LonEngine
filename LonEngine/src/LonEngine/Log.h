#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
namespace LonEngine {

	class LONENGINE_API Log {
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr < spdlog::logger> s_ClientLogger;
		static std::shared_ptr < spdlog::logger> s_CoreLogger;
	};
}
//core macros
#define LE_CORE_TRACE(...)	::LonEngine::Log::GetCoreLogger()->trace(__VA_ARGS__) 
#define LE_CORE_INFO(...)	::LonEngine::Log::GetCoreLogger()->info(__VA_ARGS__) 
#define LE_CORE_ERROR(...)	::LonEngine::Log::GetCoreLogger()->error(__VA_ARGS__) 
#define LE_CORE_FATAL(...)	::LonEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__) 
#define LE_CORE_WARN(...)	::LonEngine::Log::GetCoreLogger()->warn(__VA_ARGS__) 

//client macros
#define LE_TRACE(...)		::LonEngine::Log::GetClientLogger()->trace(__VA_ARGS__) 
#define LE_INFO(...)		::LonEngine::Log::GetClientLogger()->info(__VA_ARGS__) 
#define LE_WARN(...)		::LonEngine::Log::GetClientLogger()->warn(__VA_ARGS__) 
#define LE_ERROR(...)		::LonEngine::Log::GetClientLogger()->error(__VA_ARGS__) 
#define LE_FATAL(...)		::LonEngine::Log::GetClientLogger()->fatal(__VA_ARGS__) 

