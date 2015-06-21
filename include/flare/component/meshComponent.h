#pragma once
#include "component/component.h"

namespace flare {
	class Model;

	class MeshComponent : public Component<MeshComponent, ComponentQueue::RENDER> {
	public:
		MeshComponent();
		~MeshComponent();

		void Update();
		void Render();

		Model* m_model;
	private:

	};
}