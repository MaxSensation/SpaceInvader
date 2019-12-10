#ifndef ENEMY_H
#define ENEMY_H

#include "MovingSprite.h"

namespace ge {
	class Enemy : public MovingSprite
	{
		Enemy(int posX, int posY);
	};
}

#endif