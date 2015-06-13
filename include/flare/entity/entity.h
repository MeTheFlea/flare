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
	
		Entity();
		~Entity();
	protected:

	};
}