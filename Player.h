#ifndef PLAYER_H
#define PLAYER_H

#include "MovingSprite.h"
#include "GameInput.h"
#include "LaserBeam.h"
#include <vector>
#include "Scene.h"
#include "LaserHandler.h"

namespace ge {
	class Player : public MovingSprite, public GameInput
	{
		public:			
			Player(int* sWidth, int* sHeight, Scene* scene);			
			~Player();
			void updateKeyInput(SDL_Event* event);			
			void update(float delta);
			bool isDead();
		private:
			void limitPlayerMovement();
			void moveRight();
			void moveLeft();
			void stopLeft();
			void stopRight();
			void fire();
			void stopFire();
			
			float playerSpeed = 0.0f;
			bool bIsDead = false;
			bool bReadyToFire = true;
			bool bCanMoveRight = true;
			bool bCanMoveLeft = true;

			Scene* scene;
	};
}
#endif