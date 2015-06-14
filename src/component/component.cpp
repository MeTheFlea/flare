#include "component/component.h"

std::vector<std::function<void()>> flare::Components::s_updateFunctions;
std::vector<std::function<void()>> flare::Components::s_renderFunctions;

