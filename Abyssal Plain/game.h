#pragma once

#include "Graphics.h"
#include "texturewrapper.h"

class Game
{

private:
	bool running;
	
public:
	
	Game() : running{ false }
	{
		Game::eventLoop();
	}

	~Game(){}


	void eventLoop();

};

