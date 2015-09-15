#include "graphics/renderer.h"
#include "structs/model.h"
#include "graphics/renderer_openGL.h"
#include "core/logger.h"
using namespace flare;

Renderer* Renderer::s_instance = nullptr;

Renderer::Renderer() :
	m_api( GraphicsAPI::Unknown ) {

}

Renderer::~Renderer() {

}

Renderer* Renderer::GetInstance() {
	if( s_instance == nullptr ) {
		s_instance = new Renderer_OpenGL();
	}
	return s_instance;
}

void Renderer::Render() {
	const int size = m_renderQueue.size();
	for( int i = 0; i < size; ++i ) {
		m_renderQueue[i]->Render();
	}
}

void Renderer::AddToQueue( Model* a_model ) {
	m_renderQueue.push_back( a_model );
}

//void Renderer::AddToQueue( Mesh* a_mesh ) { // shader and mesh...

//}