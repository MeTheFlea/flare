#include "component/meshComponent.h"
#include "core/logger.h"
#include "structs/model.h"

using namespace flare;

MeshComponent::MeshComponent() {
	m_model = Model::LoadMesh( "cubeman.obj" );
}

MeshComponent::~MeshComponent() {
	delete m_model;
}

void MeshComponent::Update() {
	
}

void MeshComponent::Render() {
	Renderer::GetInstance()->AddToQueue( m_model );
}