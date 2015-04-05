#include "external/glfw.h"

int main() {
	GLFWwindow* pWindow;

	if( !glfwInit() ) {
		glfwTerminate();
		return 1;
	}

	pWindow = glfwCreateWindow( 1280, 768, "Flare v3", NULL, NULL );
   if( !pWindow ) {
      glfwTerminate();
      return 1;
	}

	glfwMakeContextCurrent( pWindow );
   glfwSwapInterval( 1 );

	while( !glfwWindowShouldClose( pWindow ) ) {


		glfwSwapBuffers( pWindow );
		glfwPollEvents();
	}

	glfwDestroyWindow( pWindow );
	glfwTerminate();
	return 0;
}