#include "core/renderer.h"

#include "core/renderer_openGL.h"
using namespace flare;

Renderer* Renderer::s_instance = nullptr;

Renderer::Renderer() {

}

Renderer::~Renderer() {

}

Renderer* Renderer::GetInstance() {
	if( s_instance == nullptr ) {
		s_instance = new Renderer_OpenGL();
	}
	return s_instance;
}