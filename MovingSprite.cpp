#include "MovingSprite.h"
#include <SDL.h>

namespace ge{
	MovingSprite::~MovingSprite()
	{
	}
	void MovingSprite::translate(int x, int y)
	{				
		position.x = x;
		position.y = y;
	}	
}
