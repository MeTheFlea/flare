#pragma once
#include "component/component.h"
#include "external/stl.h"

namespace flare {
	class TestComponent : public Component<TestComponent, ComponentQueue::UPDATE> {
	public:
		TestComponent();
		~TestComponent();
		void Update();

		std::string m_message;
	private:
		float m_timer;
	};
}