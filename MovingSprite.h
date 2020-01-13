#ifndef MOVINGSPRITE_H
#define MOVINGSPRITE_H
#include "Sprite.h"
#include "Vector2.h"
namespace ge {
	class MovingSprite : public Sprite
	{
	public:		
		void translate(float x, float y);
	protected:
		Vector2 velocity;
		MovingSprite(float posX, float posY, int width, int height, const char* imgDestination) : Sprite(posX, posY, width, height, imgDestination) {};
	private:		
		MovingSprite(const MovingSprite&) = delete;
		const MovingSprite& operator=(const MovingSprite&) = delete;		
	};
}

#endif