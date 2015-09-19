#pragma once
#include "external/stl.h"
#include "util/typedefs.h"

namespace flare {
	class PoolBase {
	public:
		PoolBase() :
			m_freeID( 0 ) {

		}
		virtual ~PoolBase() {}

		virtual void Delete( PoolID a_id ) = 0;
	protected:
		std::map<PoolID, PoolIndex> m_IDToIndex;
		std::map<PoolIndex, PoolID> m_indexToID;
		PoolID m_freeID;
	private:

	};
}