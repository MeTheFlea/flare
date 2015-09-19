#pragma once
#include "component/component.h"

namespace flare {
	class Entity {
	public:
		template<class T>
		Handle<T> AddComponent() {
			static_assert(std::is_base_of<ComponentBase, T>::value, "You can only add components!" );
			Handle<T> retVal = T::s_pPool.New();

			retVal->SetEntity( this );
			
			m_components.push_back( new Handle<T>( retVal ) );

			return retVal;
		}

		template<class T>
		void DestroyComponent() {
			for( size_t i = 0; i < m_components.size(); ++i ) {
				if( dynamic_cast<Handle<T>*>( m_components[i] ) != nullptr ) {
					m_components[i]->DeleteObj();
					delete m_components[i];
					m_components.erase( m_components.begin() + i );
					return;
				}
			}
		}

		template<class T>
		Handle<T> GetComponent() {
			return T::FindFromEntity( this );
		}

		template<class T>
		static T* Create() {
			T* entity = new T();
			s_entities.push_back( entity );
			return entity;
		}

		static void CleanUp() {
			for( unsigned int i = 0; i < s_entities.size(); ++i ) {
				delete s_entities[i];
			}
			s_entities.clear();
		}

		static void Destroy( Entity*& a_pEntity ) {
			auto findResult = std::find( s_entities.begin(), s_entities.end(), a_pEntity );
			if( findResult != s_entities.end() ) {
				delete (*findResult);
				s_entities.erase( findResult );
				a_pEntity = nullptr;
			}
		}

	protected:
		Entity();
		virtual ~Entity();
		
	private:
		static std::vector<Entity*> s_entities;
		std::vector<HandleBase*> m_components;

		void DestroyAllComponents();
	};
}