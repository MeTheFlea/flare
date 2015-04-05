#pragma once
#include "external/glfw.h"
#include "core/gameBase.h"
#include "core/inputManager.h"

#define MapGLFWToInput( a, b ) case a: code = b; break;

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

		// run the main loop of the templated Game set in the constructor of the engine (this will call OnUpdate() and OnRender() on the game, and Reset() on the Input manager appropriately)
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

		static void KeyCallback( GLFWwindow*, int a_key, int, int a_action, int ) {
			bool down = ( a_action != GLFW_RELEASE );

			KeyCode code = KeyCode::Count;

			switch( a_key ) {
				MapGLFWToInput( GLFW_KEY_A, KeyCode::A );
				MapGLFWToInput( GLFW_KEY_B, KeyCode::B );
				MapGLFWToInput( GLFW_KEY_C, KeyCode::C );
				MapGLFWToInput( GLFW_KEY_D, KeyCode::D );
				MapGLFWToInput( GLFW_KEY_E, KeyCode::E );
				MapGLFWToInput( GLFW_KEY_F, KeyCode::F );
				MapGLFWToInput( GLFW_KEY_G, KeyCode::G );
				MapGLFWToInput( GLFW_KEY_H, KeyCode::H );
				MapGLFWToInput( GLFW_KEY_I, KeyCode::I );
				MapGLFWToInput( GLFW_KEY_J, KeyCode::J );
				MapGLFWToInput( GLFW_KEY_K, KeyCode::K );
				MapGLFWToInput( GLFW_KEY_L, KeyCode::L );
				MapGLFWToInput( GLFW_KEY_M, KeyCode::M );
				MapGLFWToInput( GLFW_KEY_N, KeyCode::N );
				MapGLFWToInput( GLFW_KEY_O, KeyCode::O );
				MapGLFWToInput( GLFW_KEY_P, KeyCode::P );
				MapGLFWToInput( GLFW_KEY_Q, KeyCode::Q );
				MapGLFWToInput( GLFW_KEY_R, KeyCode::R );
				MapGLFWToInput( GLFW_KEY_S, KeyCode::S );
				MapGLFWToInput( GLFW_KEY_T, KeyCode::T );
				MapGLFWToInput( GLFW_KEY_U, KeyCode::U );
				MapGLFWToInput( GLFW_KEY_V, KeyCode::V );
				MapGLFWToInput( GLFW_KEY_W, KeyCode::W );
				MapGLFWToInput( GLFW_KEY_X, KeyCode::X );
				MapGLFWToInput( GLFW_KEY_Y, KeyCode::Y );
				MapGLFWToInput( GLFW_KEY_Z, KeyCode::Z );

				MapGLFWToInput( GLFW_KEY_ESCAPE, KeyCode::ESCAPE );
				MapGLFWToInput( GLFW_KEY_ENTER, KeyCode::RETURN );
				MapGLFWToInput( GLFW_KEY_SPACE, KeyCode::SPACE );
				MapGLFWToInput( GLFW_KEY_LEFT_SHIFT, KeyCode::LSHIFT );
				MapGLFWToInput( GLFW_KEY_RIGHT_SHIFT, KeyCode::RSHIFT );
				MapGLFWToInput( GLFW_KEY_LEFT_ALT, KeyCode::LALT );
				MapGLFWToInput( GLFW_KEY_RIGHT_ALT, KeyCode::RALT );
				MapGLFWToInput( GLFW_KEY_BACKSPACE, KeyCode::BACKSPACE );
			}
			
			if( code != KeyCode::Count ) {
				Input.SetKey( code, down );
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

#undef MapGLFWToInput