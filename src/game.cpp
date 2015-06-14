#include "game.h"
#include "core/inputManager.h"
#include "core/timeManager.h"
#include "core/logger.h"

#include "core/renderer.h"
#include "component/meshComponent.h"

#include "entity/entity.h"

using namespace flare;

Renderer* g_renderer;

void Game::OnInit() {
	g_renderer = Renderer::GetInstance();
	g_renderer->SetClearColour( 0.1f, 0.2f, 0.1f );

	InitKeyBindings();
}

void Game::InitKeyBindings() {
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