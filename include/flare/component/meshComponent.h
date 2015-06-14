#pragma once
#include "component/component.h"

namespace flare {
	class MeshComponent : public Component<MeshComponent, 20, ComponentQueue::UPDATE | ComponentQueue::RENDER> {
	public:
		MeshComponent();
		~MeshComponent();

		void Update();
		void Render();

	private:

	};
}