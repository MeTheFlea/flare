#pragma once
#include "core/gameBase.h"

class Game : public GameBase {
public:
		
protected:
	template <class TGame>
	friend class flare::Engine;

	void OnInit();
	void OnUpdate();
	void OnRender();

	void OnQuit();

	Game() {}
	~Game() {}
private:
	void InitKeyBindings();
};