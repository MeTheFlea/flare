#pragma once
#include "core/handle.h"
#include "core/pool.h"
#include "core/timeManager.h"

namespace flare {
	class Entity;

	class Components {
	public:
		static void Update() { 
			for( unsigned int i = 0; i < m_updateFunctions.size(); ++i ) {
				m_updateFunctions[i]();
			}
		}

		template<class T>
		static void RegisterTypeUpdate( std::function<void()> a_updateFunction ) {
			m_updateFunctions.push_back( a_updateFunction );
		}
	private:
		static std::vector<std::function<void()>> m_updateFunctions;
	};

	class ComponentBase {
	public:
		void SetEntity(Entity* a_pEntity) {
			m_pEntity = a_pEntity;
		}

		virtual void Update() {}

		Entity* m_pEntity;
	protected:
		ComponentBase() : m_pEntity( nullptr ) {}
		virtual ~ComponentBase() {}
	};

	template<class T, int SIZE, bool UPDATE>
	class Component : public ComponentBase {};

	template<class T, int SIZE>
	class Component<T, SIZE, false> : public ComponentBase {
	public:
		static Pool<T, SIZE> s_pPool;

		static void UpdateAll() {
			int components = s_pPool.GetSize();
			for( int i = 0; i < components; ++i ) {
				s_pPool[i].Update();
			}
		}

	protected:
		Component() {

		}
	};
	template<class T, int SIZE>
	Pool<T, SIZE> Component<T, SIZE, false>::s_pPool;

	template<class T, int SIZE>
	class Component<T, SIZE, true> : public ComponentBase {
	public:
		static Pool<T, SIZE> s_pPool;

		static void UpdateAll() {
			int components = s_pPool.GetSize();
			for( int i = 0; i < components; ++i ) {
				s_pPool[i].Update();
			}
		}

	protected:
		Component() {
			static bool registered = false;
			if( !registered ) {
				Components::RegisterTypeUpdate<T>( std::function<void()>( &Component<T, SIZE, true>::UpdateAll ) );
				registered = true;
			}
		}
	};

	template<class T, int SIZE>
	Pool<T, SIZE> Component<T, SIZE, true>::s_pPool;
}