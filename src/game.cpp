#include "game.h"
#include "core/inputManager.h"
#include "core/timeManager.h"
#include "core/logger.h"

#include "core/renderer.h"
#include "component/meshComponent.h"

#include "entity/entity.h"

using namespace flare;

Renderer* g_renderer;

Entity* g_entity = nullptr;

void Game::OnInit() {
	g_renderer = Renderer::GetInstance();
	g_renderer->SetClearColour( 0.1f, 0.2f, 0.1f );

	//g_entity = Entity::Create<Entity>();
	for( int i = 0; i < 21; ++i ) {
		Entity* entity = Entity::Create<Entity>();
		entity->AddComponent<MeshComponent>()->m_number = i;
	}

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