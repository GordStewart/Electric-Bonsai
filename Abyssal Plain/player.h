#pragma once
#include "Graphics.h"


class Player {

	int x;
	int y;

	Player();
	~Player();

	void update(Graphics& graphics);
};