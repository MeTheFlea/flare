#pragma once
#include "util/typedefs.h"
#include "core/poolBase.h"

namespace flare {
	class HandleBase {
	public:
		HandleBase( PoolID a_id, PoolBase* a_pPool ) :
			m_id( a_id ),
			m_pPool( a_pPool ) {
		}

		virtual ~HandleBase() {}

		virtual void DeleteObj() {
			if( m_pPool != nullptr) {
				m_pPool->Delete( m_id );
			}
		}

	protected:
		PoolID m_id;
		PoolBase* m_pPool;
	private:

	};	

	template<class T>
	class Pool;

	template<class T>
	class Handle : public HandleBase {
	public:
		Handle() :
			HandleBase( 0, nullptr ),
			m_pRealPool( nullptr ) {
		}
		Handle( PoolID a_id, Pool<T>* a_pPool ) :
			HandleBase( a_id, a_pPool ),
			m_pRealPool( a_pPool ) {
		}
		~Handle() {}

		T* operator->() {
			if( m_pRealPool != nullptr ) {
				return m_pRealPool->GetObj( m_id );
			}
			else {
				return nullptr;
			}
		}

		bool operator==( const std::nullptr_t& a_pNull ) {
			return operator->() == a_pNull;
		}

		void DeleteObj() override {
			if( m_pRealPool != nullptr ) {
				m_pRealPool->Delete( m_id );
			}
		}
		

	private:
		Pool<T>* m_pRealPool;
	};
}