#pragma once
#include "core/handle.h"
#include "core/logger.h"

#include <new>

namespace flare {
	template<class T, int SIZE>
	class Pool {
	public:
		Pool() :
			m_freeIndex( 0 ) {
			m_pool = (T*)( malloc( sizeof( T ) * ( SIZE + 1 ) ) );

		}
		~Pool() {
			Clear();
			free( m_pool );
		}

		Handle<T> New() {
			flareassert( m_freeIndex < SIZE, "component pool is full!" );
			
			// using placement new to plop down a new component inside the pool
			T* component = new( &m_pool[m_freeIndex++] ) T();

			Handle<T> handle( component );
		
			return handle;
		}

		void Delete( T* a_obj ) {
			if( a_obj == nullptr ) { return; }

			flareassert( m_freeIndex > 0, "deleting empty pool!" );

			// finding the index of the object relative to the start of the pool
			int index = *((int*)(a_obj)) - *((int*)(m_pool));
			
			// need to manually the destructor on the object
			a_obj->~T();


			Handle<T>::InvalidateHandles( a_obj );
			Swap( index, --m_freeIndex );
		}

		int GetSize() const { 
			return m_freeIndex;
		}

		Handle<T> operator[]( int a_index ) {
			return Handle<T>( m_pool[a_index] );
		}
	private:
		void Clear() {
			for( int i = 0; i < m_freeIndex; ++i ) {
				Handle<T>::InvalidateHandles( &m_pool[i] );
				(&m_pool[i])->~T();
				
			}
			m_freeIndex = 0;
		}

		void Swap( int a_index1, int a_index2 ) {
			T& obj1 = m_pool[a_index1];
			
			T& obj2 = m_pool[a_index2];
			
			T& tmp = m_pool[SIZE];
			
			tmp = obj1;
			obj1 = obj2;
			obj2 = tmp;
			Handle<T>::UpdateHandles( &obj1, &obj2 );
		}

		// fixed size array of objects in the pool
		T* m_pool;

		int m_freeIndex;
	};
}