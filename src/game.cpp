#include "game.h"
#include "core/inputManager.h"
#include "core/timeManager.h"
#include "core/logger.h"

#include "graphics/renderer.h"
#include "component/meshComponent.h"

#include "entity/entity.h"

#include "structs/model.h"

#include "core/resources.h"

#include "component/testComponent.h"

using namespace flare;

Entity* g_pEntity;

void Game::OnInit() {
	Renderer::GetInstance()->SetClearColour( 0.1f, 0.2f, 0.1f );
	Resources::GetInstance()->SetAssetDir( "assets/" );

	
	for( int i = 0; i < 4; ++i ) {
		auto entity = Entity::Create<Entity>();
		entity->AddComponent<MeshComponent>();
		auto comp = entity->AddComponent<TestComponent>();
		comp->m_message = std::to_string( i );

		if( i == 0 ) {
			g_pEntity = entity;
		}
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

	if( Input.GetKeyDown( KeyCode::SPACE ) ) {
		if( g_pEntity->GetComponent<TestComponent>() == nullptr ) {
			g_pEntity->AddComponent<TestComponent>()->m_message = std::string( "recreated" );
		}
		else {
			g_pEntity->GetComponent<TestComponent>()->m_message = std::string( "lasdasdlkasdjkla" );
		}
	}
	if( Input.GetKeyDown( KeyCode::RETURN ) ) {
		g_pEntity->DestroyComponent<TestComponent>();
	}

}

void Game::OnRender() {
	// render
}

void Game::OnQuit() {
	// clean up

}