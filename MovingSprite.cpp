#include "MovingSprite.h"
#include <SDL.h>

namespace ge{
	void MovingSprite::translate(float x, float y)
	{				
		position.setX(x);
		position.setY(y);
	}	
}
