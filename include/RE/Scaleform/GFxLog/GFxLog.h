#pragma once

#include "RE/Scaleform/GFxLoader/GFxState.h"
#include "RE/Scaleform/GFxLog/GFxLogBase.h"


namespace RE
{
	class GFxLog :
		public GFxState,		   // 00
		public GFxLogBase<GFxLog>  // 18
	{
	public:
		inline static constexpr auto RTTI = RTTI_GFxLog;


		GFxLog();
		virtual ~GFxLog() = default;  // 00

		// add
		virtual void LogMessageVarg(LogMessageType a_messageType, const char* a_fmt, std::va_list a_argList);  // 01

		void LogMessageByType(LogMessageType a_messageType, const char* a_fmt, ...);
	};
	static_assert(sizeof(GFxLog) == 0x20);
}
