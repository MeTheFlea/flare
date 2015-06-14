#include "game.h"
#include "core/inputManager.h"
#include "core/timeManager.h"
#include "core/logger.h"

#include "entity/entityTest.h"
using namespace flare;

#include "component/printNumberComponent.h"

Entity** test;
Handle<PrintNumberComponent> comp;

Game::Game() {
	test = new Entity*[10];
	for( int i = 0; i < 10; ++i ) {
		test[i] = Entity::Create<EntityTest>();
		test[i]->GetComponent<PrintNumberComponent>()->m_number = i;

		if( i == 5 ) {
			comp = test[i]->GetComponent<PrintNumberComponent>();
		}
	}
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
		//Entity::Destroy( test );
		test[0]->DestroyComponent<PrintNumberComponent>();
	}
	if( Input.GetKeyDown( KeyCode::Y ) ) {
		if( comp != nullptr ) {
			comp->m_pEntity->DestroyComponent( comp );
		}
	}
}

void Game::OnRender() {
	// render
}

void Game::OnQuit() {
	// clean up
	Entity::CleanUp();
	delete[] test;
}