#include "entity/entity.h"
using namespace flare;

std::vector<Entity*> Entity::s_entities;

Entity::Entity() {

}

Entity::~Entity() {
	DestroyAllComponents();
}

void Entity::DestroyAllComponents() {
	for( unsigned int i = 0; i < m_components.size(); ++i ) {
		m_components[i]->DeleteObj();
		delete m_components[i];
	}
	m_components.clear();
}
