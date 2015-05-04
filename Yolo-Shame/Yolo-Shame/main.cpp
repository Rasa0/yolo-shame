#include<crtdbg.h>

#include"Game.h"

int main() {

#if defined(DEBUG) | defined(_DEBUG)
	// Enable run-time memory check for debug builds.
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	Game myGame;
	myGame.Run();

	return 0;
}