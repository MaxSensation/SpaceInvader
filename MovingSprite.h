#ifndef MOVINGSPRITE_H
#define MOVINGSPRITE_H
#include "Sprite.h"
#include "Vector2.h"
namespace ge {
	class MovingSprite : public Sprite
	{
	public:		
		void translate(int x, int y);
	protected:
		Vector2 velocity;
		MovingSprite(int posX, int posY, int width, int height, const char* imgDestination) : Sprite(posX, posY, width, height, imgDestination) {};
	private:		
		MovingSprite(const MovingSprite&) = delete;
		const MovingSprite& operator=(const MovingSprite&) = delete;		
	};
}

#endif