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
		const char* getImgDest();		
		SDL_Rect* getScreen();
		SDL_Rect* getSpriteRect();
		SDL_Texture* getTexture();
		virtual void update(float delta);
		Sprite(int posX, int posY, int width, int height, const char* imgDestination) :
			GraphicObject2D(posX, posY, width, height),
			imgDestination(imgDestination)
		{
			init();
		};
		void render();
		void updatePos();
	protected:		
		void init();

		const char* imgDestination;
		SDL_Texture* texture = nullptr;
		SDL_Rect screen;
		SDL_Rect spriteRect;		
	};
}

#endif