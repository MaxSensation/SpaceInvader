#ifndef TEXT_H
#define TEXT_H

#include "GraphicObject2D.h"
#include <SDL_ttf.h>

namespace ge{
	class Text : GraphicObject2D
	{
		public:		
			static Text* getInstance(int posX, int posY, int width, int height, std::string font, int fontSize, std::string text);
			~Text();
			void setColor(SDL_Color newColor);
			void setText(std::string newText);			
			void render();
		private:
			Text(int posX, int posY, int width, int height, std::string font, int fontSize, std::string text);
			const Text& operator=(const Text&) = delete;
			void UpdateTextues();
			TTF_Font* font = nullptr;
			SDL_Surface* surface = nullptr;
			SDL_Texture* texture = nullptr;
			SDL_Color color = { 255, 255, 255 };
			std::string text;
	};
}

#endif // !TEXT_H