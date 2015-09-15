#include "component/testComponent.h"
#include "core/logger.h"
#include "core/timeManager.h"
using namespace flare;

TestComponent::TestComponent() :
	m_timer( 0.0f ) {
}

TestComponent::~TestComponent() {

}

void TestComponent::Update() {
	const float time = 1.0f;

	if( ( m_timer += Time.GetDeltaTime() ) > time ) {
		m_timer -= time;

		Log.Info( ( "Tick: " + m_message ).c_str() );
	}
}