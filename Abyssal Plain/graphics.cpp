#include "graphics.h"
#include "game.h"
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>



Graphics::Graphics() {

	sdlWindow = NULL;
	sdlRenderer = NULL;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		//if succeeded create the window
		sdlWindow = SDL_CreateWindow("Abyssal Plain", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Game::kScreenWidth, Game::kScreenHeight, SDL_WINDOW_SHOWN);

		//if window is successfully created, create the renderer
		if (sdlWindow != 0)
		{
			sdlRenderer = SDL_CreateRenderer(sdlWindow, -1, 0);

			
		}
	}
}


void Graphics::clear()
{
	SDL_RenderClear(sdlRenderer); // clear the renderer to the drasw colour
}

void Graphics::present()
{
	SDL_RenderPresent(sdlRenderer); // draw to the screen
}

void Graphics::shutdown()
{
	SDL_DestroyRenderer(sdlRenderer);
	SDL_DestroyWindow(sdlWindow);
	sdlWindow = NULL;
	sdlRenderer = NULL;

	SDL_Quit();
}