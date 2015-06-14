#pragma once
#include "component/component.h"

namespace flare {
	class Entity {
	public:
		template<class T>
		Handle<T> AddComponent() {
			Handle<T> retVal = T::s_pPool.New();
			retVal->SetEntity( this );
			
			Handle<ComponentBase> base( retVal.operator->() );
			m_components.push_back( base );

			return retVal;
		}

		template<class T>
		void DestroyComponent( Handle<T>& a_component ) {
			auto findResult = std::find( m_components.begin(), m_components.end(), a_component.operator->() );
			if( findResult != m_components.end() ) {
				Components::Delete( a_component.operator->() );
				m_components.erase( findResult );
			}	
		}

		template<class T>
		Handle<T> GetComponent() {
			return T::s_pPool.FindFromEntity( this );
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
		std::vector<Handle<ComponentBase>> m_components;

		void DestroyAllComponents();
	};
}