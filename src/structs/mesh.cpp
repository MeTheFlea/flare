#include "structs/mesh.h"
#include "core/renderer.h"
#include <assimp/Importer.hpp>
#include "core/logger.h"
using namespace flare;

Mesh::Mesh() {
	
}

Mesh* Mesh::LoadMesh() {
	Renderer::GraphicsAPI api = Renderer::GetGraphicsAPI();
	switch( api ) {
		case Renderer::GraphicsAPI::OpenGL:
			Log.Debug( "openGL mesh" );
		break;
	}

	return nullptr;
}