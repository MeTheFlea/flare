#include "game.h"
#include "core/inputManager.h"
#include "core/timeManager.h"
#include "core/logger.h"

#include "entity/entityTest.h"
using namespace flare;

#include "component/printNumberComponent.h"

Entity* test;

Game::Game() {
	test = Entity::Create<EntityTest>();
}

Game::~Game() {

}

void Game::OnInit() {
	// init
	Input.BindButton( "Quit", KeyCode::ESCAPE );
}

void Game::OnUpdate() {
	Components::Update();
	// update
	if( Input.GetButtonDown( "Quit" ) ) {
		Quit();
	}

	if( Input.GetKeyDown( KeyCode::T ) ) {
		Entity::Destroy( test );
		//test2->DestroyComponent( secondComp );
	}
}

void Game::OnRender() {
	// render
}

void Game::OnQuit() {
	// clean up
	Entity::CleanUp();
}