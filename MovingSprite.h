#ifndef MOVINGSPRITE_H
#define MOVINGSPRITE_H
#include "Sprite.h"
#include "Vector2.h"
namespace ge {
	class MovingSprite : public Sprite
	{
	public:
		virtual ~MovingSprite();
		MovingSprite(const std::string name, int posX, int posY, int width, int height, const char* imgDestination) : Sprite(name, posX, posY, width, height, imgDestination) {};
		void Translate(int x, int y);
	protected:
		Vector2 velocity;		
	private:
	};
}

#endif