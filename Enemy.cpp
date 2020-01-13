#include "Enemy.h"
#include "LaserHandler.h"

namespace ge{
	Enemy* Enemy::getInstance(float posX, float posY, float speed)
	{
		return new Enemy(posX, posY, speed);
	}

	Enemy::~Enemy()
	{		
	}

	Enemy::Enemy(float posX, float posY, float speed) :
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
		translate(position.getX(), position.setY(position.getY() + 15.0f));
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
		if (LaserHandler::getInstance()->checkCollision(getSpriteRect()))
		{
			std::cout << "Enemy hit!" << std::endl;
			die();
		}
	}

	void Enemy::fire() {
		std::cout << "Enemy fired" << std::endl;		
		LaserHandler::getInstance()->addLaser((position.getX() + width / 2 - 5), position.getY() + height, false);
	}

	void Enemy::update(float delta) {		
		checkCollision();
		position += velocity * delta;
	}

	void Enemy::setFire(bool status) {
		bCanFire = status;
	}

	bool Enemy::canFire() {
		return bCanFire;
	}
}
