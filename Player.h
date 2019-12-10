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
			void MoveRight();
			void MoveLeft();
			void StopLeft();			
			void StopRight();
			void Fire();
			void StopFire();
			~Player();
			void UpdateKeyInput(SDL_Event* event);
			void LimitPlayerMovement();
			void Update(float delta);
		private:
			Scene* scene;
			float playerSpeed = 0.0f;
			bool bReadyToFire = true;
			bool bCanMoveRight = true;
			bool bCanMoveLeft = true;
	};
}
#endif