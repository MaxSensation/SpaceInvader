#ifndef TEXT_H
#define TEXT_H

#include "GraphicObject2D.h"
#include <SDL_ttf.h>

namespace ge{
	class Text : GraphicObject2D
	{
		public:
			Text(int posX, int posY, int width, int height, std::string font, int fontSize, std::string text);
			~Text();
			void setColor(SDL_Color newColor);
			void setText(std::string newText);
			void render();
		private:
			TTF_Font* font = nullptr;
			SDL_Color color = { 255, 255, 255 };
			SDL_Surface* surface = nullptr;
			SDL_Texture* texture = nullptr;
			std::string text;
	};
}

#endif // !TEXT_H