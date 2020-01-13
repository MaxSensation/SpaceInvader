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
		void updateSpeed(double speed);
		void fire();
		bool canFire();
		void setFire(bool status);		
		static Enemy* getInstance(int posX, int posY, double speed);
		~Enemy();
	private:		
		Enemy(int posX, int posY, double speed);
		void die();
		void checkCollision();		
		void update(float delta);		
		bool bIsDead = false;
		bool bCanFire = true;
		double speed;
	};
}

#endif