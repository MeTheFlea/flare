#pragma once
#include "component/component.h"

namespace flare {
	class PrintNumberComponent : public Component<PrintNumberComponent, 20, true> {
	public:
		PrintNumberComponent();
		~PrintNumberComponent() {}

		void Update();

		float m_time;
	private:
		float m_timer;
	};
}