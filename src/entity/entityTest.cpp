#include "entity/entityTest.h"

#include "component/printNumberComponent.h"

using namespace flare;

EntityTest::EntityTest() {
	AddComponent<PrintNumberComponent>();
}
