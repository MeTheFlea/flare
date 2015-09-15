#include "component/meshComponent.h"
#include "core/logger.h"
#include "structs/model.h"

#include "core/resources.h"

using namespace flare;

MeshComponent::MeshComponent() {
	m_model = Resources::GetInstance()->LoadModel( "cubeman.obj" );
}

MeshComponent::~MeshComponent() {
	delete m_model;
}

void MeshComponent::Update() {
	
}

void MeshComponent::Render() {
	Renderer::GetInstance()->AddToQueue( m_model );
}