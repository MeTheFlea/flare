#pragma once
#include "core/handle.h"
#include "core/pool.h"
#include "core/timeManager.h"

namespace flare {
	class Entity;

	class ComponentBase {
	public:

	protected:
		ComponentBase() {}
		virtual ~ComponentBase() {}
	};

	class Components {
	public:
		static void Update();

		template<class T>
		static void RegisterTypeUpdate() {

		}
	private:
		
	};

	template<class T, int SIZE, bool UPDATE>
	class Component : public ComponentBase {
	public:
		static Pool<T, SIZE> s_pPool;

		static void UpdateAll() {
			int components = s_pPool.GetSize();
			for( int i = 0; i < components; ++i ) {
				//s_pPool[i]
			}
		}
	protected:
		Component() {
			if( UPDATE ) {
				Components::RegisterTypeUpdate<T>();
			}
		}

		virtual ~Component() {}
	};

	template<class T, int SIZE, bool UPDATE>
	Pool<T, SIZE> Component<T, SIZE, UPDATE>::s_pPool;
}