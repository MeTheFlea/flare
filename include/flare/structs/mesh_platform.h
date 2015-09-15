#pragma once
#include "graphics/renderer.h"

namespace flare {
	class Mesh;

	class Mesh_Platform {
	public:
		Mesh_Platform() {}
		virtual ~Mesh_Platform() {}

		virtual void Refresh( const Mesh& a_mesh );
		virtual void Render( const Mesh& a_mesh ) = 0;

	protected:
		virtual void Set( const Mesh& a_mesh ) = 0;
		virtual void Clean() = 0;
	private:

	};
}