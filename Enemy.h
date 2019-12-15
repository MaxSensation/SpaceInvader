#ifndef ENEMY_H
#define ENEMY_H

#include "MovingSprite.h"

namespace ge {
	class Enemy : public MovingSprite
	{
	public:
		Enemy(int posX, int posY);
		bool isDead();
	private:
		void die();
		void checkCollision();
		void update(float delta);
		bool bIsDead = false;
	};
}

#endif