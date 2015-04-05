#include "core/engine.h"
#include "game.h"

int main() {
	flare::Engine<Game> engine( "flare v3", 1280, 768 );
	engine.Run();
	return 0;
}