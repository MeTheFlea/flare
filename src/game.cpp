#include "game.h"
#include "core/inputManager.h"
#include "core/timeManager.h"
#include <iostream>
using namespace flare;

// TODO: logger (Log.Debug() / Log.Warning() / Log.Fatal())
// TODO: add vld

float m_timer = 0.0f;

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
		Time.SetTimescale( 0.5f );
	}

	m_timer += Time.GetDeltaTime();

	printf( "%f\n", m_timer );
}

void Game::OnRender() {
	// render
}

void Game::OnQuit() {
	// clean up
}