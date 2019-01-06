#include "game.h"
#include <iostream>

SDL_Window* m_pWindow = NULL;
SDL_Renderer* m_pRenderer = NULL;

Game::Game(){


}

Game::~Game(){}

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}
	// initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL initialization was  successful.\n";
		// init the window
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		if (m_pWindow != 0)  //the window was created successfully
		{
			std::cout << "Window created successfully.\n";

			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
			if (m_pRenderer != 0) // the renderer was created successfully
			{
				std::cout << "Renderer created successfully.\n";

				SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);

				m_textureManager.load("assets/player_idle.png", "player_idle", m_pRenderer);
			}

			else
			{
				std::cout << "Renderer init failure!\n";
				return false;
			}
		}
		else
		{
			std::cout << "Window init failure!\n";
			return false;
		}
	}

	else
	{
		std::cout << "SDL initialization failure!\n";
		return false;
	}

	std::cout << "Init success!\n";
	//everything inited successfully, so start the main loop
	m_bRunning = true; 

	return true;
}

void Game::eventHandler()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_bRunning = false;
			break;

		default:
			break;

		}
	}
}

void Game::update()
{

}



void Game::render()
{
	// clear the renderer to the draw colour
	SDL_RenderClear(m_pRenderer);

	m_textureManager.draw("player_idle", 100, 100, 32, 32, m_pRenderer);

	//draw to the screen
	SDL_RenderPresent(m_pRenderer);
}

void Game::clean()
{
	std::cout << "Destroying all your stuff...\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
	std::cout << "*Boom* It's gone.";
}