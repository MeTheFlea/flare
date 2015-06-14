#include "entity/entity.h"
using namespace flare;

std::vector<Entity*> Entity::s_entities;

Entity::Entity() {

}

Entity::~Entity() {
	DestroyAllComponents();
}

void Entity::DestroyAllComponents() {
	while( m_components.size() != 0 ) {
		DestroyComponent( m_components[0] );
	}
}
