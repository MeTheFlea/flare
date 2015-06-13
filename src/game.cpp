#include "game.h"
#include "core/inputManager.h"
#include "core/timeManager.h"
#include "core/logger.h"

#include "entity/entityTest.h"
using namespace flare;

EntityTest* test;

Game::Game() {
	test = new EntityTest[2];
	for( int i = 0; i < 2; ++i ) {
		test[i].SetNumber( i );
	}
}

Game::~Game() {

}

void Game::OnInit() {
	// init
	Input.BindButton( "Quit", KeyCode::ESCAPE );
}

void Game::OnUpdate() {
	// update
	if( Input.GetButtonDown( "Quit" ) ) {
		Quit();
	}

	if( Input.GetKeyDown( KeyCode::Y ) ) {
		test[0].DeleteComponent();
		//flareassert( false, "test message" );
	}
}

void Game::OnRender() {
	// render
}

void Game::OnQuit() {
	// clean up
	delete[] test;
}