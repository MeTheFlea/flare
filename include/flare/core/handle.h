#pragma once
#include "external/stl.h"
#include "core/logger.h"

namespace flare {
	template<class T>
	class Handle {
	public:
		Handle() :
			m_pObject( nullptr ) {

		}
		Handle( T* a_pObject ) :
			m_pObject( a_pObject ) {
			AddHandle();
		}

		Handle( const Handle<T>& a_other ) :
			m_pObject( a_other.operator->() ) {
			AddHandle();
		}

		void AddHandle() {
			s_handles.insert( std::pair<T*, Handle<T>*>( m_pObject, this ) );
			Log.Debug( "added handle" );
		}

		void RemoveHandle() {
			auto findResult = s_handles.equal_range( m_pObject );

			auto it = findResult.first;
			while( it != findResult.second ) {
				if( (*it).second == this ) {
					it = s_handles.erase( it );
					Log.Debug( "deleted handle" );
					break;
				}
				++it;
			}
		}

		~Handle() {
			RemoveHandle();
		}

		Handle<T>& operator=( const Handle<T>& a_other ) {
			RemoveHandle();
			m_pObject = a_other.operator->();
			AddHandle();

			return *this;
		}

		void SetObject( T* a_pObj ) {
			m_pObject = a_pObj;
		}

		T* operator->() { return m_pObject; }
		T* operator->() const { return m_pObject; }

		T& operator*() { return *m_pObject; }
		const T& operator*() const { return *m_pObject; }

		bool operator==( T* a_pOther ) const {
			return m_pObject == a_pOther;
		}
		bool operator!=( T* a_pOther ) const {
			return m_pObject != a_pOther;
		}

		static void InvalidateHandles( T* a_obj ) {
			auto findResultOld = s_handles.equal_range( a_obj );

			for( auto it = findResultOld.first; it != findResultOld.second; ++it ) {
				(*it).second->SetObject( nullptr );
			}

			s_handles.erase( a_obj );
			Log.Debug( "deleted handle" );
		}

		static void UpdateHandles( T* a_oldAddr, T* a_newAddr ) {
			if( s_handles.size() == 0 ) { return; }
			auto findResultOld = s_handles.equal_range( a_oldAddr );
			std::vector<Handle<T>*> oldVec;
			std::vector<Handle<T>*> newVec;

			for( auto it = findResultOld.first; it != findResultOld.second; ++it ) {
				oldVec.push_back( (*it).second );
			}

			s_handles.erase( a_oldAddr );

			auto findResultNew = s_handles.equal_range( a_newAddr );

			for( auto it = findResultNew.first; it != findResultNew.second; ++it ) {
				newVec.push_back( (*it).second );
			}

			s_handles.erase( a_newAddr );

			for( auto it = oldVec.begin(); it != oldVec.end(); ++it ) {
				(*it)->m_pObject = a_newAddr;
				s_handles.insert( std::pair<T*, Handle<T>*>( a_newAddr, (*it) ) );
			}
			for( auto it = newVec.begin(); it != newVec.end(); ++it ) {
				(*it)->m_pObject = a_oldAddr;
				s_handles.insert( std::pair<T*, Handle<T>*>( a_oldAddr, (*it) ) );
			}
		}
	private:
		T* m_pObject;

		static std::unordered_multimap<T*, Handle<T>*> s_handles;
	};

	template<class T>
	std::unordered_multimap<T*, Handle<T>*> Handle<T>::s_handles;

}