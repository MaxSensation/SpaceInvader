#include "Player.h"
#include <iostream>


namespace ge{
	Player::Player(const std::string name, int posX, int posY, int width, int height, const char* imgDestination) : MovingSprite(name, posX, posY, width, height, imgDestination)
	{		
	}

	void Player::MoveRight()
	{
		std::cout << "Player Move Left" << std::endl;
		Translate(1,0);
	}

	void Player::MoveLeft()
	{
		std::cout << "Player Move Right" << std::endl;
		Translate(-1, 0);
	}

	void Player::Fire()
	{
		//Add Fire Function
		std::cout << "Player Fire" << std::endl;
	}

	Player::~Player()
	{

	}

	void Player::UpdateKeyInput(SDL_Event* event) {			
		if((*event).type == SDL_KEYDOWN)
		{
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
		}		
	}
}