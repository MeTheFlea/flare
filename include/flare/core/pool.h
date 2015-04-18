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
			for( int i = 0; i < m_freeIndex; ++i ) {
				(&m_pool[i])->~T();
			}
			free( m_pool );
		}

		Handle<T> New() {
			flareassert( m_freeIndex < SIZE, "component pool is full!" );
			T* component = new( &m_pool[m_freeIndex++] ) T();

			Handle<T> handle( component );
		
			return handle;
		}

		void Swap() {
			T* obj1 = &m_pool[0];
			
			T* obj2 = &m_pool[1];
			
			T* tmp = &m_pool[SIZE];
			
			memcpy( tmp, obj1, sizeof( T ) );
			memcpy( obj1, obj2, sizeof( T ) );
			memcpy( obj2, tmp, sizeof( T ) );

			Handle<T>::UpdateHandles( obj1, obj2 );
		}
	private:
		T* m_pool;

		int m_freeIndex;
	};
}