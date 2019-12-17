#include "Text.h"
#include "GameEngine.h"
namespace ge {
	Text::Text(int posX, int posY, int width, int height, std::string fontFile, int fontSize, std::string text) :
		GraphicObject2D(posX, posY, width, height),
		font(TTF_OpenFont(fontFile.c_str(), fontSize)),
		text(text)
	{
		UpdateTextues();
	}
		
	Text::~Text() {
		SDL_DestroyTexture(texture);		
		TTF_CloseFont(font);
	}
	void Text::setColor(SDL_Color newColor)
	{
		color = newColor;
		UpdateTextues();
	}
	void Text::setText(std::string newText)
	{
		text = newText;		
		UpdateTextues();
	}

	void Text::UpdateTextues() {
		surface = TTF_RenderText_Solid(font, text.c_str(), color);
		texture = SDL_CreateTextureFromSurface(gameengine.getRenderer(), surface);
		SDL_FreeSurface(surface);
	}

	void Text::render()
	{
		SDL_QueryTexture(texture, NULL, NULL, &width, &height);
		SDL_Rect dstrect = { position.x, position.y, width, height };
		SDL_RenderCopy(gameengine.getRenderer(), texture, NULL, &dstrect);
	}
}