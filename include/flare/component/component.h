#pragma once
#include "core/handle.h"
#include "core/pool.h"
#include "core/timeManager.h"
#include "core/logger.h"

namespace flare {
	class Entity;

	class ComponentBase {
	public:
		void SetEntity( Entity* a_pEntity ) {
			m_pEntity = a_pEntity;
		}

		virtual void Update() {}

		Entity* m_pEntity;

		
	protected:
		friend class Components;
		ComponentBase() : m_pEntity( nullptr ) {}
		virtual ~ComponentBase() {}

		virtual void RemoveFromPool() {
			
		}
		
	};

	class Components {
	public:
		static void Update() { 
			for( unsigned int i = 0; i < s_updateFunctions.size(); ++i ) {
				s_updateFunctions[i]();
			}
		}

		template<class T>
		static void RegisterTypeUpdate( std::function<void()> a_updateFunction ) {
			s_updateFunctions.push_back( a_updateFunction );
		}
	protected:
		friend class Entity;

		static void Delete( ComponentBase* a_pComponent ) {
			a_pComponent->RemoveFromPool();
		}
	private:
		static std::vector<std::function<void()>> s_updateFunctions;
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
		Component() {}
		virtual ~Component() {}

		void RemoveFromPool() {
			s_pPool.Delete( (T*)this );
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

		virtual ~Component() {}

		void RemoveFromPool() {
			s_pPool.Delete( (T*)this );
		}
	};

	template<class T, int SIZE>
	Pool<T, SIZE> Component<T, SIZE, true>::s_pPool;
}