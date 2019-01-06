#pragma once
#include <string>
#include <SDL.h>
#include <map>

struct TextureManager {

	bool load(std::string fileName, std::string id, SDL_Renderer* m_pRenderer);

	//draw
	void draw(std::string id, int x, int y, int width, int height, SDL_Renderer* m_pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

	//drawframe
	void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* m_pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);


	std::map<std::string, SDL_Texture*> m_textureMap;

};