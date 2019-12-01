#include "MovingSprite.h"
#include <SDL.h>

namespace ge{
	MovingSprite::~MovingSprite()
	{
	}
	void MovingSprite::Translate(int x, int y)
	{
		posX += x;
		posY += y;
	}
}
