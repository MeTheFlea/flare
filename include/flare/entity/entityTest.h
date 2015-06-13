#pragma once
#include "entity/entity.h"

#include "component/printNumberComponent.h"

namespace flare {
	class EntityTest : public Entity {
	public:
		EntityTest();
		~EntityTest() {}

		void SetNumber( int a_number );
		void PrintNumber();

		void DeleteComponent();
	private:
		Handle<PrintNumberComponent> m_numberPrint;

		
	};
}