#include "component/printNumberComponent.h"
#include "core/logger.h"
#include "core/timeManager.h"
using namespace flare;

PrintNumberComponent::PrintNumberComponent() : 
	m_time( 1.0f ),
	m_timer( 0.0f ) {

}

void PrintNumberComponent::Update() {
	if( ( m_timer += Time.GetDeltaTime() ) > m_time ) {
		m_timer -= m_time;
		Log.Debug( "Tick" );
	}
}