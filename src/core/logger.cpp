#include "core/logger.h"
#include "core/timeManager.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdexcept>
#include <iomanip>
#include <sstream>

using namespace flare;

Logger Log;

Logger::Logger() {

}

Logger::~Logger() {

}

#ifndef NDEBUG
void Logger::Debug( const char* a_message, ... ) {
	fprintf( stderr, "%s|Debug\t| ", FormatTimeToString( Time.GetElapsedMilliseconds() ).c_str() );

	va_list args;
	va_start( args, a_message );
	Write( a_message, args );
	va_end( args );
}
#else
void Logger::Debug( const char*, ... ) {

}
#endif

void Logger::Info( const char* a_message, ... ) {
	fprintf( stderr, "%s|Info\t| ", FormatTimeToString( Time.GetElapsedMilliseconds() ).c_str() );

	va_list args;
	va_start( args, a_message );
	Write( a_message, args );
	va_end( args );
}

void Logger::Warning( const char* a_message, ... ) {
	fprintf( stderr, "%s|WARN\t| \a", FormatTimeToString( Time.GetElapsedMilliseconds() ).c_str() );

	va_list args;
	va_start( args, a_message );
	Write( a_message, args );
	va_end( args );
}

void Logger::Fatal( const char* a_message, ... ) {
	fprintf( stderr, "%s|FATAL\t| \a", FormatTimeToString( Time.GetElapsedMilliseconds() ).c_str() );

	va_list args;
	va_start( args, a_message );
	Write( a_message, args );
	va_end( args );
}

void Logger::Write( const char* a_message, const va_list& a_list ) {
	//va_list args;
	//va_start( args, a_message );
	vfprintf( stderr, a_message, a_list );
	//va_end( args );
	fprintf( stderr, "\n" );
}

std::string Logger::FormatTimeToString( float a_timeElapsed ) {
	const float totalHours = ((a_timeElapsed/1000.0f)/60.0f)/60.0f;
	const float minutes = ((totalHours-((int)totalHours))*60.0f);
	const float seconds = ((minutes-((int)minutes))*60.0f);
	const int milliseconds = (int)a_timeElapsed % 1000;

	std::stringstream milliSecondsString;
	milliSecondsString << std::setfill( '0' ) << std::setw(3) << milliseconds;
	std::stringstream secondsString;
	secondsString << std::setfill( '0' ) << std::setw(2) << (int)seconds;
	std::stringstream minutesString;
	minutesString << std::setfill( '0' ) << std::setw(2) << (int)minutes;
	//std::stringstream hoursString;
	//hoursString << std::setfill( '0' ) << std::setw(2) << (int)totalHours;
	
	std::string time = "" + minutesString.str() + ":" + secondsString.str() + ":" + milliSecondsString.str();

	return time;
}