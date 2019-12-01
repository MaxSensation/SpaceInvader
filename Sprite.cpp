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

	void Sprite::Init()
	{		
		//TODO Fix transparency
		SDL_Surface* image = IMG_Load(imgDestination);
		texture = SDL_CreateTextureFromSurface(gameengine.GetRenderer(), image);
		SDL_FreeSurface(image);
		screen = {0,0,*gameengine.GetScreenWidth(), *gameengine.GetScreenHeight()};
		spriteRect = { posX, posY, width, height};
	}
}