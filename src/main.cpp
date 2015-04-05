#include "external/glfw.h"

int main() {
	GLFWwindow* pWindow;

	if( !glfwInit() ) {
		glfwTerminate();
		return 1;
	}

	pWindow = glfwCreateWindow( 640, 480, "Flare v3", NULL, NULL );
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