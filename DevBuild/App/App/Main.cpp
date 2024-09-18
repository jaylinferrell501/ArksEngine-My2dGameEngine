#include "Game.h"

int main()
{
	Game game;

	game.InitializeApp("PrototypeGameTest", "Assets/Assets.zip", 960, 480);

	game.RunEngine();

	game.De_initialize();

	return 0;
}
