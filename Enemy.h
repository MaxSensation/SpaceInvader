#ifndef ENEMY_H
#define ENEMY_H

#include "MovingSprite.h"

namespace ge {
	class Enemy : public MovingSprite
	{
	public:		
		bool isDead();
		void moveRight();
		void moveLeft();
		void moveDown();
		void updateSpeed(float speed);
		void fire();
		bool canFire();
		void setFire(bool status);		
		static Enemy* getInstance(float posX, float posY, float speed);
		~Enemy();
	private:		
		Enemy(float posX, float posY, float speed);
		void die();
		void checkCollision();		
		void update(float delta);		
		bool bIsDead = false;
		bool bCanFire = true;
		float speed;
	};
}

#endif