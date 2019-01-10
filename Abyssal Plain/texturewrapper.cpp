#include "texturewrapper.h"


TextureWrapper::TextureWrapper()
{
	//Initialize
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}

TextureWrapper::~TextureWrapper()
{
	//Deallocate
	free();
}

bool TextureWrapper::loadFromFile(std::string path, std::string id, Graphics& graphics)
{
	//Remove existing texture
	free();

	//THe finished texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(graphics.renderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}
		else
		{
			//Add the texture to the list (textureMap)
			m_textureMap[id] = newTexture;
			//Get Image Dimensions
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}

		//Get rid of the old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	//Return success
	mTexture = newTexture;
	return mTexture != NULL;
}

void TextureWrapper::free()
{
	//Free texture (if it exists)
	if (mTexture != NULL)
	{
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

void TextureWrapper::render(std::string id, Graphics& graphics, int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	//Set clip rendering dimensions
	if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopyEx(graphics.renderer, m_textureMap[id], clip, &renderQuad, angle, center, flip);
}

int TextureWrapper::getWidth()
{
	return mWidth;
}

int TextureWrapper::getHeight()
{
	return mHeight;
}
