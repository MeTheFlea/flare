#pragma once
#include "structs/mesh_platform.h"

#include "external/opengl.h"

namespace flare {
	class Mesh_OpenGL : public Mesh_Platform {
	public:
		Mesh_OpenGL();
		~Mesh_OpenGL();
		
		void Render( const Mesh& a_mesh ) override;
	protected:
		void Set( const Mesh& a_mesh ) override;
		void Clean() override;

	private:
		GLuint m_vao;
		GLuint m_vertexBuffer;
	};
}