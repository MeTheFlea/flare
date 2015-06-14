#pragma once
#include "core/renderer.h"
#include "external/glm.h"

namespace flare {
	class Renderer_OpenGL : public Renderer {
	public:

		void ClearFrame();
		void SetClearColour( float a_red, float a_green, float a_blue, float a_alpha = 1.0f );

	private:

	};
}