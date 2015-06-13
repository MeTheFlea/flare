#pragma once
#include "component/component.h"

namespace flare {
	class PrintNumberComponent : public Component<PrintNumberComponent, 20, false> {
	public:
		PrintNumberComponent() : m_number( 0 ) {}
		~PrintNumberComponent() {}

		void PrintNumber();

		int m_number;
	private:
		
	};
}