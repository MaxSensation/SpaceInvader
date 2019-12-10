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

	const char* Sprite::GetImgDest()
	{
		return imgDestination;
	}

	SDL_Rect* Sprite::GetScreen()
	{
		return &screen;
	}

	SDL_Rect* Sprite::GetSpriteRect()
	{
		return &spriteRect;
	}
	
	SDL_Texture* Sprite::GetTexture()
	{
		return texture;
	}

	void Sprite::Update(float delta)
	{
	}

	void Sprite::Render()
	{
		SDL_RenderCopy(gameengine.GetRenderer(), GetTexture(), GetScreen(), GetSpriteRect());	
	}

	void Sprite::UpdatePos() {
		spriteRect.x = static_cast<int>(position.x);
		spriteRect.y = static_cast<int>(position.y);
	}

	void Sprite::Init()
	{				
		SDL_Surface* optimizedSurface = NULL;
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
			texture = SDL_CreateTextureFromSurface(gameengine.GetRenderer(), optimizedSurface);									
			SDL_FreeSurface(loadedSurface);
			SDL_FreeSurface(optimizedSurface);
		}
		SCREENWIDTH = *gameengine.GetScreenWidth();
		SCREENHEIGHT = *gameengine.GetScreenHeight();
		screen = { 0,0,SCREENWIDTH,SCREENHEIGHT };
		spriteRect = { static_cast<int>(position.x), static_cast<int>(position.y), width, height };
	}
}