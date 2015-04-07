#include "core/timeManager.h"

using namespace flare;

TimeManager Time;

TimeManager::TimeManager() :
	m_timescale( 1.0f ),	
	m_deltaTime( 0.0f ),	
	m_unscaledDeltaTime( 0.0f ),	
	m_currentTime( std::chrono::high_resolution_clock::now() ) {
	
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
}