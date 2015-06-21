#include "component/meshComponent.h"
#include "core/logger.h"

using namespace flare;

MeshComponent::MeshComponent() {
	m_number = 0;
	m_timer = 0.0f;

	m_time = 1.0f;
}

MeshComponent::~MeshComponent() {

}

void MeshComponent::Update() {
	if( ( m_timer += Time.GetDeltaTime() ) > m_time ) {
		m_timer -= m_time;
		Log.Debug( "%i", m_number );
	}
}

void MeshComponent::Render() {
	
}