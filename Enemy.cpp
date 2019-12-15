#include "Enemy.h"
#include "LaserHandler.h"

namespace ge{
	Enemy::Enemy(int posX, int posY, float speed) :
		MovingSprite(posX, posY, 24, 24, "Enemy.png"),
		speed(speed)
	{
		std::cout << "Enemy Created" << std::endl;
	}

	bool Enemy::isDead()
	{
		return bIsDead;
	}

	void Enemy::moveRight()
	{
		velocity.x = speed;
	}

	void Enemy::moveLeft()
	{
		velocity.x = speed * -1;
	}

	void Enemy::moveDown()
	{
		translate(position.x, position.y + 15);
	}

	void Enemy::updateSpeed(float speed) {
		this->speed = speed;
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
		position += velocity * delta;
	}
}
