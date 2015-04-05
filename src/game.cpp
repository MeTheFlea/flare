#include "game.h"
#include "core/inputManager.h"

Game::Game() {

}

Game::~Game() {

}

void Game::OnInit() {
	// init
	Input.AddKeyMap( "Quit", flare::KeyCode::ESCAPE );
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