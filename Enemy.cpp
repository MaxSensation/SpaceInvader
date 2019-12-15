#include "Enemy.h"
#include "LaserHandler.h"

namespace ge{
	Enemy::Enemy(int posX, int posY) :
		MovingSprite(posX, posY, 24, 24, "Enemy.png")
	{
		std::cout << "Enemy Created" << std::endl;
	}

	bool Enemy::isDead()
	{
		return bIsDead;
	}

	void Enemy::die()
	{
		std::cout << "Enemy Destroyd!" << std::endl;
		bIsDead = true;
	}

	void Enemy::checkCollision() {
		if (laserHandler.checkCollision(&spriteRect))
		{
			std::cout << "Enemy hit!" << std::endl;
			die();
		}
	}

	void Enemy::update(float delta) {
		checkCollision();
	}
}
