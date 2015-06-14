#include "game.h"
#include "core/inputManager.h"
#include "core/timeManager.h"
#include "core/logger.h"

#include "core/renderer.h"

using namespace flare;

Renderer* m_renderer;

void Game::OnInit() {
	m_renderer = Renderer::GetInstance();
	m_renderer->SetClearColour( 0.1f, 0.1f, 0.2f );

	// init
	Input.BindButton( "Quit", KeyCode::ESCAPE );
}

void Game::OnUpdate() {
	// update
	if( Input.GetButtonDown( "Quit" ) ) {
		Quit();
	}
}

void Game::OnRender() {
	// render
}

void Game::OnQuit() {
	// clean up

}