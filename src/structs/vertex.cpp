#include "structs/vertex.h"
using namespace flare;

Vertex::Vertex( glm::vec3 a_position, glm::vec3 a_normal, glm::vec2 a_uv, glm::vec3 a_binormal, glm::vec3 a_tangent ) :
	m_position( a_position ),
	m_normal( a_normal ),
	m_binormal( a_binormal ),
	m_tangent( a_tangent ),
	m_uv( a_uv ) {

}