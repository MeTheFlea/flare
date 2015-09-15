#include "structs/mesh_platform.h"

using namespace flare;

void Mesh_Platform::Refresh( const Mesh& a_mesh ) {
	Clean();
	Set( a_mesh );
}