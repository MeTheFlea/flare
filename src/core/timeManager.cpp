#include "core/timeManager.h"

using namespace flare;

TimeManager Time;

TimeManager::TimeManager() :
	m_unscaledDeltaTime( 0.0f ),
	m_deltaTime( 0.0f ),
	m_timescale( 1.0f ),
	m_elapsedMilli( 0.0f ),
	m_currentTime( std::chrono::steady_clock::now() ) {
	
}

TimeManager::~TimeManager() {

}

void TimeManager::SetDeltaTime( const float a_deltaTime ) {
	m_unscaledDeltaTime = a_deltaTime;
	m_deltaTime = m_unscaledDeltaTime * m_timescale;
}

void TimeManager::StartFrame() {
	auto now = std::chrono::high_resolution_clock::now();
	std::chrono::duration<float> time = now - m_currentTime;
	SetDeltaTime( time.count() );
	m_currentTime = now;

	typedef std::chrono::duration<float, std::milli> milliseconds;
	
	m_elapsedMilli += std::chrono::duration_cast<milliseconds>( time ).count();
}