#include "Player.h"
#include <iostream>


namespace ge{
	Player::Player(const std::string name, int posX, int posY, int width, int height, const char* imgDestination) :
		MovingSprite(name, posX, posY, width, height, imgDestination),
		playerSpeed(1.0f)
	{		
	}

	void Player::MoveRight()
	{
		velocity.x = playerSpeed;
		std::cout << "Player Move Left" << std::endl;		
	}

	void Player::MoveLeft()
	{
		velocity.x = -playerSpeed;
		std::cout << "Player Move Right" << std::endl;	
	}

	void Player::StopLeft()
	{
		velocity.x = 0;
		std::cout << "Player Stopped Right" << std::endl;		
	}

	void Player::StopRight()
	{
		velocity.x = 0;
		std::cout << "Player Stopped Right" << std::endl;		
	}

	void Player::Fire()
	{
		//Add Fire Function
		std::cout << "Player Fire" << std::endl;
	}

	void Player::UpdateKeyInput(SDL_Event* event) {			
		switch ((*event).type) {
			case SDL_KEYDOWN:
				switch ((*event).key.keysym.sym)
				{
				case SDLK_RIGHT:
					MoveRight();
					break;
				case SDLK_LEFT:
					MoveLeft();
					break;
				case SDLK_SPACE:
					Fire();
					break;
				}
				break;
			case SDL_KEYUP:
				switch ((*event).key.keysym.sym)
				{
				case SDLK_RIGHT:
					StopRight();
					break;
				case SDLK_LEFT:
					StopLeft();
					break;
				}
				break;
			
		}
	}

	void Player::Update(float delta) {
		position += velocity * delta;
	}

	Player::~Player()
	{

	}
}