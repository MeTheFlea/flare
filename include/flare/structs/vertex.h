#pragma once
#include "external/glm.h"

namespace flare {
	class Vertex {
	public:
		Vertex( glm::vec3 a_position, glm::vec3 a_normal, glm::vec2 a_uv, glm::vec3 a_binormal = glm::vec3(), glm::vec3 a_tangent = glm::vec3() );

		glm::vec3 m_position;
		glm::vec3 m_normal;
		glm::vec3 m_binormal;
		glm::vec3 m_tangent;

		glm::vec2 m_uv;
	};
}