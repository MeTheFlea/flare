#include "game.h"
#include "core/inputManager.h"
using namespace flare;

Game::Game() {

}

Game::~Game() {

}

void Game::OnInit() {
	// init
	Input.AddKeyMap( "Quit", KeyCode::ESCAPE );
	Input.AddKeyMap( "Quit", KeyCode::F );
	Input.AddKeyMap( "Quit", KeyCode::LSHIFT );

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