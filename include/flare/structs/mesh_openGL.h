#pragma once
#include "structs/mesh_platform.h"

#include "external/opengl.h"

namespace flare {
	class Mesh_OpenGL : public Mesh_Platform {
	public:
		Mesh_OpenGL();
		~Mesh_OpenGL();
		
		void Refresh( const Mesh& a_mesh ) override;
		void Render( const Mesh& a_mesh ) override;
	private:
		void Clean();
		void Set( const Mesh& a_mesh );

		GLuint m_vao;
		GLuint m_vertexBuffer;
	};
}