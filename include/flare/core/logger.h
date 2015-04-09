#pragma once
#include "external/stl.h"

namespace flare {
	class Logger {
	public:
		Logger();
		~Logger();

		void Debug( const char* a_message, ... );
		void Info( const char* a_message, ... );
		void Warning( const char* a_message, ... );
		void Fatal( const char* a_message, ... );
	private:
		void Write( const char* a_message, const va_list& a_list );

		std::string FormatTimeToString( float a_timeElapsed );
	};
}

extern flare::Logger Log;