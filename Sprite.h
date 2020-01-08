#ifndef SPRITE_H
#define SPRITE_H
#include "GraphicObject2D.h"
#include <iostream>
#include <SDL.h>

namespace ge {
	class Sprite : public GraphicObject2D
	{
	public:		
		~Sprite();
		const char* getImgDest();
		SDL_Rect* getScreen();
		SDL_Rect* getSpriteRect();
		virtual void update(float delta);
		void updatePos();
		void render();
	protected:				
		Sprite(int posX, int posY, int width, int height, const char* imgDestination) :
			GraphicObject2D(posX, posY, width, height),
			imgDestination(imgDestination)
		{
			init();
		};
		void init();		
		SDL_Texture* texture = nullptr;
		SDL_Rect screen;
		SDL_Rect spriteRect;		
		const char* imgDestination;
	};
}

#endif