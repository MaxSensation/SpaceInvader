#ifndef ENEMY_H
#define ENEMY_H

#include "MovingSprite.h"

namespace ge {
	class Enemy : public MovingSprite
	{
	public:
		Enemy(int posX, int posY);
		bool IsDead();
	private:
		void Destory();
		void CheckCollision();
		void Update(float delta);
		bool isColliding = false;
		bool isDead = false;
	};
}

#endif