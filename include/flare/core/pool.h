#pragma once
#include "core/handle.h"
#include "core/logger.h"

#include <new>

namespace flare {
	class Entity;

	template<class T>
	class Pool {
	public:
		Pool() {
			m_pool.reserve( 20 );
			m_temp = (T*)malloc( sizeof( T ) );
		}
		~Pool() {
			Clear();
			free( m_temp );
		}

		Handle<T> New() {
			auto oldCapacity = m_pool.capacity();
			T* oldStartAddr = (m_pool.data());
			m_pool.emplace_back();
			if( oldCapacity != m_pool.capacity() ) {
				T* startAddr = m_pool.data();
				for( unsigned int i = 0; i < m_pool.size()-1; ++i ) {
					Handle<T>::UpdateHandles( oldStartAddr + i, startAddr + i );
					Handle<ComponentBase>::UpdateHandles( oldStartAddr + i, startAddr + i );
				}
			}
			T* component = &m_pool[m_pool.size()-1];

			Handle<T> handle( component );
		
			return handle;
		}

		Handle<T> FindFromEntity( Entity* a_pEntity ) {
			const int size = m_pool.size();
			for( int i = 0; i < size; ++i ) {
				T* component = (T*)( &(m_pool[i]) );
				if( component->m_pEntity == a_pEntity ) {
					Handle<T> handle( component );
					return handle;
				}
			}
			return Handle<T>();
		}

		void Delete( T* const a_obj ) {
			if( a_obj == nullptr ) { return; }

			// finding the index of the object relative to the start of the pool
			int index = ( ((T*)a_obj) - ((T*)(m_pool.data())) );

			Handle<T>::InvalidateHandles( a_obj );
			Handle<ComponentBase>::InvalidateHandles( a_obj );
			Swap( index, m_pool.size()-1 );
			
			m_pool.erase( m_pool.end()-1 );
		}

		int GetSize() const { 
			return m_pool.size();
		}

		T& operator[]( int a_index ) {
			return ( m_pool[a_index] );
		}
	private:
		void Clear() {
			const int size = m_pool.size();
			for( int i = 0; i < size; ++i ) {
				Handle<T>::InvalidateHandles( &m_pool[i] );
				Handle<ComponentBase>::InvalidateHandles( &m_pool[i] );
			}
			m_pool.clear();
		}

		void Swap( int a_index1, int a_index2 ) {
			T& obj1 = m_pool[a_index1];
			
			T& obj2 = m_pool[a_index2];
			
			T& tmp = (*m_temp);
			
			memcpy( &tmp, &obj1, sizeof( T ) );
			memcpy( &obj1, &obj2, sizeof( T ) );
			memcpy( &obj2, &tmp, sizeof( T ) );

			Handle<T>::UpdateHandles( &obj1, &obj2 );
			Handle<ComponentBase>::UpdateHandles( &obj1, &obj2 );
		}

		// fixed size array of objects in the pool
		std::vector<T> m_pool;
		T* m_temp;
	};
}