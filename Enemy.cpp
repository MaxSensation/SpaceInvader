#include "Enemy.h"
#include "LaserBeam.h"

namespace ge{
	Enemy::Enemy(int posX, int posY) :
		MovingSprite("Enemy", posX, posY, 40, 40, "Player.png")
	{
	}


	void Enemy::CheckCollision() {
		/*
		for (LaserBeam laser : laserBeams)
		{

		}
		*/
	}

	void Enemy::Update(float delta) {
		CheckCollision();
	}
}
