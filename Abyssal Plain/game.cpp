#include "Game.h"




void Game::eventLoop()
{
	Graphics graphics;
	SDL_Event event;
	TextureWrapper textureWrapper;

	textureWrapper.loadFromFile("assets/player_static.png", "player", graphics);
	running = true;

	while (running)
	{
		//Handle events on queue
		while (SDL_PollEvent(&event) != 0)
		{
			//User requests quit
			if (event.type == SDL_QUIT)
			{
				running = false;
			}
		}

		graphics.clear();
		textureWrapper.render("player", graphics, 0, 0, 0, 0, 0);
		graphics.present();

	}
}

