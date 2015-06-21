#pragma once
#include "external/stl.h"
#include "structs/vertex.h"
#include "core/renderer.h"

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
		void Init( Renderer::GraphicsAPI a_api );

		Mesh_Platform* m_mesh;
	private:
		
	};
}