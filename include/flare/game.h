#pragma once
#include "core/gameBase.h"

class Game : public GameBase {
public:
	Game();
	~Game();

protected:
	template <class TGame>
	friend class flare::Engine;

	void OnInit();
	void OnUpdate();
	void OnRender();

	void OnQuit();

private:

};