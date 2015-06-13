#include "component/printNumberComponent.h"
#include "core/logger.h"
using namespace flare;

void PrintNumberComponent::PrintNumber() {
	Log.Debug( "%i", m_number );
}