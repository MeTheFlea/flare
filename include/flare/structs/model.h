#pragma once
#include "external/stl.h"
#include "structs/mesh.h"

namespace flare {
	class Model {
	public:
		static Model* LoadMesh( std::string a_asset );
		static void SetAssetDir( std::string a_dir ) { s_dir = a_dir; }

		~Model() {}

		void Render();
	protected:
		Model( std::string a_filepath );
		
		std::vector<Mesh> m_meshes;

	private:
		static std::string s_dir;
	};
}