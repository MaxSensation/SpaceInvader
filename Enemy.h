#ifndef ENEMY_H
#define ENEMY_H

#include "MovingSprite.h"

namespace ge {
	class Enemy : public MovingSprite
	{
	public:
		Enemy(int posX, int posY);
	private:
		void CheckCollision();
		void Update(float delta);
	};
}

#endif