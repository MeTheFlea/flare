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

Entity* g_entity = nullptr;

void Game::OnInit() {
	Renderer::GetInstance()->SetClearColour( 0.1f, 0.2f, 0.1f );
	Resources::GetInstance()->SetAssetDir( "assets/" );

	
	for( int i = 0; i < 10; ++i ) {
		Entity* pEntity = Entity::Create<Entity>();
		pEntity->AddComponent<MeshComponent>();
		auto compHandle = pEntity->AddComponent<TestComponent>();
		auto comp = pEntity->GetComponent( compHandle );
		comp->m_message = std::to_string( i );

		if( i == 5 ) {
			g_entity = pEntity;
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
		Entity::Destroy( g_entity );
	}
}

void Game::OnRender() {
	// render
}

void Game::OnQuit() {
	// clean up

}