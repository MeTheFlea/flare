#pragma once
#include "component/component.h"

namespace flare {
	class Entity {
	public:
		template<class T>
		Handle<T> AddComponent() {
			return T::s_pPool.New();
		}

		template<class T>
		void DestroyComponent( Handle<T>& a_component ) {
			T::s_pPool.Delete( a_component.operator->() );
		}

		void Foo() {
			if( test == nullptr ) {
				test = AddComponent<TestComponent>();
				test->test = 2;
			}
			test->Foo();
		}

		void Bar() {
			DestroyComponent( test );
		}
	
		Entity();
		~Entity();
	protected:
		Handle<TestComponent> test;


	};
}