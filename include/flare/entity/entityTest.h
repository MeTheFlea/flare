#pragma once
#include "entity/entity.h"

namespace flare {
	class EntityTest : public Entity {
	public:
		
	private:
		friend class Entity;
		EntityTest();
		~EntityTest() {}
	};
}