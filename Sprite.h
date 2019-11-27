#ifndef SPRITE_H
#define SPRITE_H
#include "GraphicObject2D.h"
#include <iostream>
#include <SDL.h>

namespace ge {
	class Sprite : public GraphicObject2D
	{
	public:
		virtual ~Sprite();
		const char* GetImgDest();		
		SDL_Rect* GetScreen();
		SDL_Rect* GetSpriteRect();
		SDL_Texture* GetTexture();
		Sprite(const std::string name, int posX, int posY, int width, int height, const char* imgDestination) : GraphicObject2D(name, posX, posY, width, height), imgDestination(imgDestination) {
			Init();
		};
	private:		
		void Init();
		const char* imgDestination;
		SDL_Texture* texture = nullptr;
		SDL_Rect screen;
		SDL_Rect spriteRect;
	};
}

#endif