#include "entity/entity.h"
using namespace flare;


Entity::Entity() {
	//AddComponent<TestComponent>();
	test = AddComponent<TestComponent>();
	test->test = 2;
}

Entity::~Entity() {

}


