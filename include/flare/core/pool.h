#pragma once
#include "core/handle.h"
#include "core/logger.h"
#include "util/typedefs.h"
#include "core/poolBase.h"
#include <new>

namespace flare {
	template<class T>
	class Pool : public PoolBase {
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
			m_pool.emplace_back();

			PoolIndex index = m_pool.size()-1;
			
			// making sure id is not already being used
			auto findResult = m_IDToIndex.find( m_freeID );
			while( findResult != m_IDToIndex.end() ) {
				m_freeID++;
			}

			PoolID id = m_freeID++;


			m_IDToIndex.insert( std::pair<PoolID, PoolIndex>( id, index ) );
			m_indexToID.insert( std::pair<PoolID, PoolIndex>( index, id ) );

			return Handle<T>( id, this );
		}

		Handle<T> GetHandleFromIndex( PoolIndex a_index ) {
			return Handle<T>( m_indexToID[a_index], this );
		}
		
		//T* GetObjFromHandle( Handle<T>& a_handle ) {
		//	return GetObj( a_handle.m_id );
		//}

		void Delete( PoolID a_id ) override {
			auto findResult = m_IDToIndex.find( a_id );
			if( findResult == m_IDToIndex.end() ) { return; }

			Swap( (*findResult).second, m_pool.size()-1 );
			
			m_pool.erase( m_pool.end()-1 );
			
			PoolIndex index = m_IDToIndex[a_id];
			m_indexToID.erase( m_indexToID.find( index ) );
			m_IDToIndex.erase( m_IDToIndex.find( a_id ) );
		}

		int GetSize() const { 
			return m_pool.size();
		}

		T& operator[]( int a_index ) {
			return m_pool[a_index];
		}

		T* GetObj( PoolID a_id ) {
			auto findResult = m_IDToIndex.find( a_id );
			if( findResult == m_IDToIndex.end() ) { return nullptr; }

			return &m_pool[(*findResult).second];
		}

		void Clear() {
			m_pool.clear();
		}
	private:
		void Swap( PoolIndex a_index1, PoolIndex a_index2 ) {
			T& obj1 = m_pool[a_index1];
			
			T& obj2 = m_pool[a_index2];
			
			T& tmp = (*m_temp);
			
			memcpy( &tmp, &obj1, sizeof( T ) );
			memcpy( &obj1, &obj2, sizeof( T ) );
			memcpy( &obj2, &tmp, sizeof( T ) );

			PoolID id1 = m_indexToID[a_index1];
			PoolID id2 = m_indexToID[a_index2];

			m_IDToIndex[id1] = a_index2;
			m_IDToIndex[id2] = a_index1;

			m_indexToID[a_index1] = id2;
			m_indexToID[a_index2] = id1;
		}

		T* m_temp;
		std::vector<T> m_pool;
	};
}