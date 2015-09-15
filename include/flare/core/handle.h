#pragma once
#include "util/typedefs.h"

namespace flare {
	class PoolBase;

	class HandleBase {
	public:
		HandleBase( PoolID a_id, PoolBase* a_pPool ) :
			m_id( a_id ),
			m_pPool( a_pPool ) {

		}

		virtual ~HandleBase() {}

		virtual PoolID GetID() const { return m_id; }
		virtual PoolBase* GetPool() const { return m_pPool; }

	protected:
		const PoolID m_id;
		PoolBase* const m_pPool;

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

	private:
		Pool<T>* const m_pRealPool;
	};
}