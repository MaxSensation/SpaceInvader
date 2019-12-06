#include "Player.h"
#include <iostream>


namespace ge{
	Player::Player(int* sWidth, int* sHeight, Scene* scene) :
		MovingSprite("Player", (*sWidth / 2) - (50 / 2), *sHeight - (50 + 10), 50, 50, "Player.bmp"),
		playerSpeed(1.0f),
		scene(scene)
	{	
		std::cout << "Player Spawned" << std::endl;
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
		std::cout << "Player Stopped Left" << std::endl;		
	}

	void Player::StopRight()
	{
		velocity.x = 0;
		std::cout << "Player Stopped Right" << std::endl;		
	}

	void Player::Fire()
	{
		if (bReadyToFire)
		{
			std::cout << "Player Fired LaserBeam" << std::endl;
			bReadyToFire = false;
			LaserBeam* laser = new LaserBeam((position.x + width / 2) - 10, position.y, true);
			laserBeams.push_back(laser);
			scene->AddSprite(laser);			
		}		
	}

	void Player::StopFire()
	{
		bReadyToFire = true;
	}

	void Player::UpdateKeyInput(SDL_Event* event) {			
		switch ((*event).type) {
			case SDL_KEYDOWN:
				switch ((*event).key.keysym.sym)
				{
				case SDLK_RIGHT:
					if (bCanMoveRight)
					{
						MoveRight();
					}					
					break;
				case SDLK_LEFT:
					if (bCanMoveLeft)
					{
						MoveLeft();
					}					
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
				case SDLK_SPACE:
					StopFire();
					break;
				}
				break;
			
		}
	}	

	void Player::LimitPlayerMovement() {				
		if (position.x > SCREENWIDTH-width)
		{							
			StopRight();
			Translate(SCREENWIDTH - width,position.y);
			bCanMoveRight = false;
		}
		if(position.x < SCREENWIDTH-width) {
			bCanMoveRight = true;
		}
		if(position.x < 0)
		{				
			StopLeft();
			Translate(0, position.y);
			bCanMoveLeft = false;
		}
		if(position.x > 0)
		{			
			bCanMoveLeft = true;
		}
	}

	void Player::RemoveLaserBeam(LaserBeam* laser) {
		std::cout << "LaserBeam Removed" << std::endl;
		scene->RemoveSprite(laser);
		
		auto it = laserBeams.begin();
		while (it != laserBeams.end())
		{
			if (*it == laser) {
				it = laserBeams.erase(it);
			}
			else {
				++it;
			}
		}
	}

	void Player::CheckLaserBeams() {
		for (LaserBeam *laser : laserBeams) {
			if (laser->OutsideBounce())
			{				
				RemoveLaserBeam(laser);				
			}
		}
	}

	void Player::Update(float delta) {		
		LimitPlayerMovement();
		CheckLaserBeams();
		position += velocity * delta;
	}

	Player::~Player()
	{

	}
}