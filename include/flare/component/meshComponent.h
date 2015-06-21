#pragma once
#include "component/component.h"

namespace flare {
	class MeshComponent : public Component<MeshComponent, ComponentQueue::UPDATE | ComponentQueue::RENDER> {
	public:
		MeshComponent();
		~MeshComponent();

		void Update();
		void Render();

		int m_number;
		float m_timer;
		float m_time;
	private:

	};
}