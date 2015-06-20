#include "core/renderer_openGL.h"
#include "external/opengl.h"
using namespace flare;

Renderer_OpenGL::Renderer_OpenGL() :
	Renderer() {
	m_api = GraphicsAPI::OpenGL;
}

void Renderer_OpenGL::ClearFrame() {
	glClear( GL_COLOR_BUFFER_BIT );
}

void Renderer_OpenGL::SetClearColour( float a_red, float a_green, float a_blue, float a_alpha ) {
	glClearColor( a_red, a_green, a_blue, a_alpha );
}
