#include "game.h"
#include "core/inputManager.h"
#include "core/timeManager.h"
#include "core/logger.h"

using namespace flare;

Game::Game() {

}

Game::~Game() {
}

void Game::OnInit() {
	// init
	Input.AddKeyMap( "Quit", KeyCode::ESCAPE );
}

void Game::OnUpdate() {
	// update
	if( Input.GetButtonDown( "Quit" ) ) {
		Quit();
	}

	if( Input.GetKeyDown( KeyCode::T ) ) {
		//Time.SetTimescale( 0.5f );	
	}
	if( Input.GetKeyDown( KeyCode::Y ) ) {
		flareassert( false, "test message" );
	}
}

void Game::OnRender() {
	// render
}

void Game::OnQuit() {
	// clean up
}