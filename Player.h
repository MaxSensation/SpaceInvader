#ifndef PLAYER_H
#define PLAYER_H

#include "MovingSprite.h"
#include "GameInput.h"

namespace ge {
	class Player : public MovingSprite, public GameInput
	{
		public:			
			Player(const std::string name, int posX, int posY, int width, int height, const char* imgDestination);
			void MoveRight();
			void MoveLeft();
			void Fire();
			~Player();
			void UpdateKeyInput(SDL_Event* event);
		private:
	};
}
#endif