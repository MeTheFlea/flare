#pragma once
#include "external/stl.h"
#include "structs/mesh.h"

namespace flare {
	class Model {
	public:
		~Model() {}

		void Render();
	protected:
		friend class Resources;
		Model( std::string a_filepath );
		
		std::vector<Mesh> m_meshes;

	private:
		void Refresh( Renderer::GraphicsAPI a_api );
	};
}