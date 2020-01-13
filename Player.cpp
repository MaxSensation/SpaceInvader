#include "Player.h"
#include "GameEngine.h"
#include <iostream>


namespace ge{
	Player::Player(int* sWidth, int* sHeight, bool* bGameOver) :
		MovingSprite((*sWidth / 2) - (50 / 2), *sHeight - (50 + 10), 50, 50, "Player.png"),
		playerSpeed(0.5f),
		bGameOver(bGameOver)
	{	
		std::cout << "Player Spawned" << std::endl;
	}

	void Player::moveRight()
	{
		velocity.setX(playerSpeed);
		std::cout << "Player Move Right" << std::endl;					
	}

	void Player::moveLeft()
	{
		velocity.setX(-playerSpeed);
		std::cout << "Player Move Left" << std::endl;	
	}

	void Player::stopLeft()
	{
		velocity.setX(0);
		std::cout << "Player Stopped Left" << std::endl;		
	}

	void Player::stopRight()
	{
		velocity.setX(0);
		std::cout << "Player Stopped Right" << std::endl;		
	}

	void Player::fire()
	{		
		if (bReadyToFire && !*bGameOver)
		{
			std::cout << "Player Fired LaserBeam" << std::endl;
			bReadyToFire = false;			
			LaserHandler::getInstance()->addLaser((position.getX() + width / 2) - 10, position.getY() - 20, true);
		}		
	}

	void Player::stopFire()
	{
		bReadyToFire = true;
	}

	void Player::updateKeyInput(SDL_Event* event) {			
		switch ((*event).type) {
			case SDL_KEYDOWN:
				switch ((*event).key.keysym.sym)
				{
				case SDLK_RIGHT:
					if (bCanMoveRight)
					{
						moveRight();
					}					
					break;
				case SDLK_LEFT:
					if (bCanMoveLeft)
					{
						moveLeft();
					}					
					break;
				case SDLK_SPACE:
					fire();
					break;
				}
				break;			
			case SDL_KEYUP:
				switch ((*event).key.keysym.sym)
				{
				case SDLK_RIGHT:
					stopRight();
					break;
				case SDLK_LEFT:
					stopLeft();
					break;
				case SDLK_SPACE:
					stopFire();
					break;
				}
				break;
			
		}
	}	

	void Player::limitPlayerMovement() {				
		if (position.getX() > * GameEngine::getInstance()->getScreenWidth() -width)
		{							
			stopRight();
			translate(*GameEngine::getInstance()->getScreenWidth() - width,position.getY());
			bCanMoveRight = false;
		}
		if(position.getX() < *GameEngine::getInstance()->getScreenWidth() -width) {
			bCanMoveRight = true;
		}
		if(position.getX() < 0)
		{				
			stopLeft();
			translate(0, position.getY());
			bCanMoveLeft = false;
		}
		if(position.getX() > 0)
		{			
			bCanMoveLeft = true;
		}
	}

	void Player::update(float delta) {
		checkCollision();
		limitPlayerMovement();				
		position += velocity * delta;
	}

	bool Player::isDead() {
		return bIsDead;
	}

	void Player::die()
	{
		bIsDead = true;
		GameEngine::getInstance()->getInputManager()->removeInput(this);
	}

	void Player::checkCollision() {
		if (LaserHandler::getInstance()->checkCollision(getSpriteRect()))
		{
			std::cout << "Player hit!" << std::endl;
			die();
		}
	}

	Player* Player::getInstance(int* sWidth, int* sHeight, bool* bGameOver)
	{
		return new Player(sWidth, sHeight, bGameOver);
	}

	Player::~Player()
	{		
		bGameOver = nullptr;
		delete(bGameOver);
	}
}