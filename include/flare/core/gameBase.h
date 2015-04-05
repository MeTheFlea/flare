#pragma once

namespace flare {
	template <class TGame>
	class Engine;
};

class GameBase {
public:
	GameBase() : m_quit( false ) {}
	virtual ~GameBase() {}

protected:
		void Quit() { m_quit = true; }

		// these get called by the engine
		virtual void OnInit() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnRender() = 0;

		virtual void OnQuit() = 0;

		// --

		bool m_quit;
private:

};