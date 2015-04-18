#pragma once
#include "core/handle.h"
#include "core/pool.h"

namespace flare {
	class Entity;

	class ComponentBase {
	public:

	protected:
		ComponentBase() {}
		virtual ~ComponentBase() {}
	};

	template<class T, int SIZE>
	class Component : public ComponentBase {
	public:

		static Pool<T, SIZE> s_pPool;
	protected:
		Component() {}
		virtual ~Component() { }

		
	};

	class TestComponent : public Component<TestComponent, 20> {
	public:
		TestComponent() {
			test = 0;
		}
		void Foo() {
			Log.Info( "%i", test );
		}
		int test;
	protected:
		
	};

	template<class T, int SIZE>
	Pool<T, SIZE> Component<T, SIZE>::s_pPool;

	
}