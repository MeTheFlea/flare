#pragma once
#include "component/component.h"

namespace flare {
	class Entity {
	public:
		template<class T>
		Handle<T> AddComponent() {
			return T::s_pPool.New();
		}

		void Foo() {
			test->Foo();
			TestComponent::s_pPool.Swap();
		}
	
		Entity();
		~Entity();
	protected:
		Handle<TestComponent> test;
	};
}