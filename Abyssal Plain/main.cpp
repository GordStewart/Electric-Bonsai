#include "game.h"

// the Game object
Game* g_game = 0;

int main(int argc, char* argv[])
{

	g_game = new Game();

	g_game->init("Abyssal Plain", 100, 100, 1280, 720, false);

	while (g_game->running())
	{
		g_game->eventHandler();
		g_game->update();
		g_game->render();
	}

	g_game->clean();

	return 0;
}