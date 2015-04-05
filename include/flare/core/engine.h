#pragma once
#include "external/glfw.h"
#include "core/gameBase.h"
#include "core/inputManager.h"

namespace flare {
	template <class TGame>
	class Engine {
	public:
		Engine( const char* a_windowTitle, int a_windowWidth, int a_windowHeight ) {
			if( !glfwInit() ) {
				glfwTerminate();
			}

			m_pWindow = glfwCreateWindow( a_windowWidth, a_windowHeight, a_windowTitle, NULL, NULL );
			if( !m_pWindow ) {
				glfwTerminate();
			}

			glfwMakeContextCurrent( m_pWindow );
			glfwSwapInterval( 1 );

			glfwSetKeyCallback( m_pWindow, KeyCallback );

			m_game.OnInit();
		}

		void Run() {
			while( !glfwWindowShouldClose( m_pWindow ) ) {
				glfwPollEvents();

				m_game.OnUpdate();
				m_game.OnRender();

				Input.Reset();
				glfwSwapBuffers( m_pWindow );
				if( m_game.m_quit ) { glfwSetWindowShouldClose( m_pWindow, true ); }
			}
		}

		static void KeyCallback( GLFWwindow* a_pWindow, int a_key, int a_scancode, int a_action, int a_mods ) {
			bool down = ( a_action != GLFW_RELEASE );

			if( a_key == GLFW_KEY_ESCAPE ) {
				Input.SetKey( KeyCode::ESCAPE, down );
			}
		}
		
		~Engine() {
			m_game.OnQuit();

			glfwDestroyWindow( m_pWindow );
			glfwTerminate();
		}

	private:
		GLFWwindow* m_pWindow;

		TGame m_game;

	};
}