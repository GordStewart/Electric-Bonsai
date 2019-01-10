#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include"Graphics.h"
#include<map>

// Texture Wrapper class
class TextureWrapper
{
public:
	//Initializes variables
	TextureWrapper();

	//Deallocates memory
	~TextureWrapper();

	//Loads image at specified path
	bool loadFromFile(std::string path, std::string id, Graphics& graphics);

	//Deallocates texture
	void free();

	//Renders texture at given point
	void render(std::string id, Graphics& graphics, int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

	//Gets image dimensions
	int getWidth();
	int getHeight();

	std::map<std::string, SDL_Texture*> m_textureMap;

private:
	//The actual hardware texture
	SDL_Texture* mTexture;

	//Image dimensions
	int mWidth;
	int mHeight;
};