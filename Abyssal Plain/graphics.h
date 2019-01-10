#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>


class Graphics
{


public:
	Graphics();
	~Graphics();

	SDL_Renderer* renderer;
	SDL_Window* window;
	
	

	bool init();
	void close();

	void clear();
	void present();


};

