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

#ifdef NDEBUG
#define flareassert( condition, message )
#else
#define flareassert( condition, message ) \
	if( !condition ) { Log.Fatal( "\n---------------\nASSERTION FAILED\nLINE: %i\nFUNCTION: %s\nMESSAGE: %s\n---------------", __LINE__, __FUNCTION__, message ); std::abort(); }
#endif