#include "structs/mesh.h"
#include "core/renderer.h"
#include "core/logger.h"
#include "structs/mesh_openGL.h"
using namespace flare;

Mesh::Mesh() :
	m_mesh( nullptr ) {

}

Mesh::~Mesh() {
	delete m_mesh;
}

void Mesh::Init( Renderer::GraphicsAPI a_api ) {
	switch( a_api ) {
		case Renderer::GraphicsAPI::OpenGL:
			m_mesh = new Mesh_OpenGL();
		break;
	}

	m_mesh->Refresh( *this );
}