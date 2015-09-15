#pragma once
#include "external/stl.h"
#include "structs/vertex.h"
#include "graphics/renderer.h"

namespace flare {
	class Mesh_Platform;

	class Mesh {
	public:
		std::vector<Vertex> m_vertices;
		std::vector<unsigned int> m_vertexIndices;

		Mesh();
		~Mesh();
	protected:
		friend class Model;
		void Refresh( Renderer::GraphicsAPI a_api );

		Mesh_Platform* m_pMesh;
	private:
		
	};
}