#pragma once
#include "core/handle.h"
#include "core/pool.h"
#include "core/timeManager.h"
#include "core/logger.h"

namespace flare {
	class Entity;

	enum ComponentQueue : unsigned int {
		UPDATE = ( 1 << 0 ),
		RENDER = ( 1 << 1 )
	};

	class ComponentBase {
	public:
		void SetEntity( Entity* a_pEntity ) {
			m_pEntity = a_pEntity;
		}

		virtual void Update() {}
		virtual void Render() {}

		Entity* m_pEntity;
	protected:
		friend class Components;
		ComponentBase() : 
			m_pEntity( nullptr ) {
		}

		virtual ~ComponentBase() {}

	};

	class Components {
	public:
		static void Update() { 
			for( unsigned int i = 0; i < s_updateFunctions.size(); ++i ) {
				s_updateFunctions[i]();
			}
		}
		static void Render() { 
			for( unsigned int i = 0; i < s_renderFunctions.size(); ++i ) {
				s_renderFunctions[i]();
			}
		}

		template<ComponentQueue T>
		static void RegisterType( std::function<void()> a_function ) {}
		
		template<>
		static void RegisterType<ComponentQueue::UPDATE>( std::function<void()> a_function ) {
			s_updateFunctions.push_back( a_function );
		}

		template<>
		static void RegisterType<ComponentQueue::RENDER>( std::function<void()> a_function ) {
			s_renderFunctions.push_back( a_function );
		}
	protected:

	private:
		static std::vector<std::function<void()>> s_updateFunctions;
		static std::vector<std::function<void()>> s_renderFunctions;
	};

	template<class T, int FLAGS>
	class Component : public ComponentBase {
	public:
		static Pool<T> s_pPool;

		static void UpdateAll() {
			int components = s_pPool.GetSize();
			for( int i = 0; i < components; ++i ) {
				s_pPool[i].Update();
			}
		}

		static void RenderAll() {
			int components = s_pPool.GetSize();
			for( int i = 0; i < components; ++i ) {
				s_pPool[i].Render();
			}
		}

		static Handle<T> FindFromEntity( Entity* a_pEntity ) {
			int components = s_pPool.GetSize();
			for( int i = 0; i < components; ++i ) {
				if( s_pPool[i].m_pEntity == a_pEntity ) {
					return s_pPool.GetHandleFromObj( s_pPool[i] );
				}
			}
		}

	protected:
		Component() {
			static bool registered = false;
			if( !registered ) {
				int flags = FLAGS;
				if( flags & ComponentQueue::UPDATE ) {
					Components::RegisterType<ComponentQueue::UPDATE>( std::function<void()>( &Component<T, FLAGS>::UpdateAll ) );
				}
				if( flags & ComponentQueue::RENDER ) {
					Components::RegisterType<ComponentQueue::RENDER>( std::function<void()>( &Component<T, FLAGS>::RenderAll ) );
				}
				registered = true;
			}
		}

		virtual ~Component() {}
	};
	template<class T, int FLAGS>
	Pool<T> Component<T, FLAGS>::s_pPool;
}