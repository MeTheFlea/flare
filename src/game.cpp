#include "game.h"
#include "core/inputManager.h"
#include "core/timeManager.h"
#include "core/logger.h"

#include "entity/entityTest.h"
using namespace flare;

#include "component/printNumberComponent.h"

EntityTest* test;
EntityTest* test2;

Handle<PrintNumberComponent> secondComp;

Game::Game() {
	test = new EntityTest();
	test->GetComponent<PrintNumberComponent>()->m_time = 1.0f;
	test2 = new EntityTest();
	secondComp = test2->GetComponent<PrintNumberComponent>();
	secondComp->m_time = 1.0f;
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
		secondComp->m_time = 5.0f;
	}
}

void Game::OnRender() {
	// render
}

void Game::OnQuit() {
	// clean up
	delete test;
	delete test2;
}