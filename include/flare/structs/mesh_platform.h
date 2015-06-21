#pragma once
#include "core/renderer.h"

namespace flare {
	class Mesh;

	class Mesh_Platform {
	public:
		Mesh_Platform() {}
		virtual ~Mesh_Platform() {}

		virtual void Refresh( const Mesh& a_mesh ) = 0;
		virtual void Render( const Mesh& a_mesh ) = 0;
	private:

	};
}