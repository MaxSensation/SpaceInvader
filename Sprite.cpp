#include "Sprite.h"
#include <iostream>
#include "GameEngine.h"
#include <SDL_image.h>

using namespace std;

namespace ge {
	Sprite::~Sprite()
	{
 		SDL_DestroyTexture(texture);
	}

	const char* Sprite::getImgDest()
	{
		return imgDestination;
	}

	SDL_Rect* Sprite::getScreen()
	{
		return &screen;
	}

	SDL_Rect* Sprite::getSpriteRect()
	{
		return &spriteRect;
	}

	void Sprite::update(float delta)
	{
	}

	void Sprite::render()
	{
		SDL_RenderCopy(gameengine.getRenderer(), texture, getScreen(), getSpriteRect());	
	}

	bool Sprite::isDestroyd()
	{
		return bDestroyd;
	}

	void Sprite::removeSprite() {
		bDestroyd = true;
	}

	void Sprite::updatePos() {		
		spriteRect.x = static_cast<int>(position.x);
		spriteRect.y = static_cast<int>(position.y);
	}

	void Sprite::init()
	{				
		SDL_Surface* optimizedSurface = nullptr;
		SDL_Surface* loadedSurface = IMG_Load(imgDestination);
		if (loadedSurface == NULL)
		{
			printf("Unable to load image %s! SDL_image Error: %s\n", imgDestination, IMG_GetError());
		}
		else
		{
			optimizedSurface = SDL_ConvertSurfaceFormat(loadedSurface, SDL_PIXELFORMAT_ARGB8888, 0);
			if (optimizedSurface == NULL)
			{
				printf("Unable to optimize image %s! SDL Error: %s\n", imgDestination, SDL_GetError());
			}			
			texture = SDL_CreateTextureFromSurface(gameengine.getRenderer(), optimizedSurface);									
			SDL_FreeSurface(loadedSurface);
			SDL_FreeSurface(optimizedSurface);
		}
				
		screen = { 0,0,*gameengine.getScreenWidth() ,* gameengine.getScreenHeight() };
		spriteRect = { static_cast<int>(position.x), static_cast<int>(position.y), width, height };
	}
}