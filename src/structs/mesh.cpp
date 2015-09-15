#include "structs/mesh.h"
#include "graphics/renderer.h"
#include "core/logger.h"
#include "structs/mesh_openGL.h"
using namespace flare;

Mesh::Mesh() :
	m_pMesh( nullptr ) {

}

Mesh::~Mesh() {
	delete m_pMesh;
}

void Mesh::Refresh( Renderer::GraphicsAPI a_api ) {
	switch( a_api ) {
		case Renderer::GraphicsAPI::OpenGL:
			m_pMesh = new Mesh_OpenGL();
		break;
	}

	m_pMesh->Refresh( *this );
}