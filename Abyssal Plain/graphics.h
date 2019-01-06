#pragma once

#include <SDL.h>
#include "game.h"

struct SDL_Rect;

struct Graphics {

	Graphics();


	void clear();
	void present();
	void shutdown();

	

public:
	SDL_Window* sdlWindow;
	SDL_Renderer* sdlRenderer;

private:
	
	

};
