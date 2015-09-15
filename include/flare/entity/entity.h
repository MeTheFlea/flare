#pragma once
#include "component/component.h"

namespace flare {
	class Entity {
	public:
		template<class T>
		Handle<T> AddComponent() {
			static_assert(std::is_base_of<ComponentBase, T>::value, "You can only add components!" );
			Handle<T> retVal = T::s_pPool.New();

			T* pComponent = T::s_pPool.GetObjFromHandle( retVal );
			pComponent->SetEntity( this );
			
			m_components.push_back( new Handle<T>( retVal ) );

			return retVal;
		}

		template<class T>
		void DestroyComponent( Handle<T>& a_component ) {
			if( a_component.GetObj() == nullptr ) { return; }
			
			auto findResult = std::find( m_components.begin(), m_components.end(), a_component );
			if( findResult != m_components.end() ) {
				a_component.DeleteObj();
				delete (*findResult);
				m_components.erase( findResult );
			}	
		}

		template<class T>
		void DestroyComponent() {
			DestroyComponent( GetComponentHandle<T>() );
		}

		template<class T>
		Handle<T> GetComponentHandle() {
			return T::FindFromEntity( this );
		}

		// dangerous
		template<class T>
		T* GetComponent( Handle<T>& a_handle ) {
			return T::s_pPool.GetObjFromHandle( a_handle );
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