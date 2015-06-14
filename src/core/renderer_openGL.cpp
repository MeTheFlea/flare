#include "core/renderer_openGL.h"
#include "external/opengl.h"
using namespace flare;

void Renderer_OpenGL::ClearFrame() {
	glClear( GL_COLOR_BUFFER_BIT );
}

void Renderer_OpenGL::SetClearColour( float a_red, float a_green, float a_blue, float a_alpha ) {
	glClearColor( a_red, a_green, a_blue, a_alpha );
}
