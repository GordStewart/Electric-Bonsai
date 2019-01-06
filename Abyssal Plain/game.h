#pragma once
#include "texture_manager.h"
#include <SDL.h>

class Game
{

public:
	Game();
	~Game();

	//simply set the running variable to true
	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void render();
	void update();
	void eventHandler();
	void clean();

	// a function to acess the private running variable
	bool running() { return m_bRunning; }

private:

	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	int m_currentFrame;
	TextureManager m_textureManager;

	bool m_bRunning;
};