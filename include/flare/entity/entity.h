#pragma once
#include "component/component.h"

namespace flare {
	class Entity {
	public:
		template<class T>
		Handle<T> AddComponent() {
			Handle<T> retVal = T::s_pPool.New();
			retVal->SetEntity( this );
			return retVal;
		}

		template<class T>
		void DestroyComponent( Handle<T>& a_component ) {
			T::s_pPool.Delete( a_component.operator->() );
		}

		template<class T>
		Handle<T> GetComponent() {
			return T::s_pPool.FindFromEntity( this );
		}
	
		Entity();
		~Entity();
	protected:
		

	private:
		typedef size_t Key;
		template<class T>
		Key HashType() const {
			static std::hash<std::string> hashFunc;
			Key hashed = hashFunc( typeid( T ).name() );
		}
	};
}