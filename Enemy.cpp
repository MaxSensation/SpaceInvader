#include "Enemy.h"
#include "LaserHandler.h"

namespace ge{
	Enemy::Enemy(int posX, int posY) :
		MovingSprite("Enemy", posX, posY, 40, 40, "Player.png")
	{
	}

	bool Enemy::IsDead()
	{
		return isDead;
	}

	void Enemy::Destory()
	{
		std::cout << "Enemy Destroyd!" << std::endl;
		isDead = true;
	}

	void Enemy::CheckCollision() {
		if (laserHandler.CheckCollition(&spriteRect) && !isColliding)
		{
			std::cout << "Enemy hit!" << std::endl;
			Destory();
			isColliding = true;
		}
		else if(!laserHandler.CheckCollition(&spriteRect) && isColliding)
		{
			isColliding = false;
		}
	}

	void Enemy::Update(float delta) {
		CheckCollision();
	}
}
