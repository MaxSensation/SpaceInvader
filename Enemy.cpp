#include "Enemy.h"
#include "LaserHandler.h"

namespace ge{
	Enemy::Enemy(int posX, int posY, double speed) :
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
		velocity.setX(speed);
	}

	void Enemy::moveLeft()
	{
		velocity.setX(speed * -1);
	}

	void Enemy::moveDown()
	{
		translate(position.getX(), position.setY(position.getY() + 15));
	}

	void Enemy::updateSpeed(double speed) {
		this->speed = speed;
	}

	void Enemy::die()
	{
		std::cout << "Enemy Destroyd!" << std::endl;
		bIsDead = true;
	}

	void Enemy::checkCollision() {
		if (laserHandler.checkCollision(getSpriteRect()))
		{
			std::cout << "Enemy hit!" << std::endl;
			die();
		}
	}

	void Enemy::fire() {
		std::cout << "Enemy fired" << std::endl;		
		laserHandler.addLaser((position.getX() + width / 2 - 5), position.getY() + height, false);
	}

	void Enemy::update(float delta) {		
		checkCollision();
		position += velocity * delta;
	}

	void Enemy::setFire(bool status) {
		bCanFire = status;
	}

	Enemy* Enemy::getInstance(int posX, int posY, double speed)
	{
		return new Enemy(posX, posY, speed);
	}

	bool Enemy::canFire() {
		return bCanFire;
	}
}
