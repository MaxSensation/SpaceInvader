#ifndef GAME_H
#define GAME_H

#include "GameEngine.h"
#include "GameInput.h"
#include "Player.h"

namespace ge {
	class Game
	{
		public:
			Game();
			~Game();
		private:
			Player* player = nullptr;
			Scene* scene = nullptr;
			int SCREENWITDH = 0;
			int SCREENHEIGHT = 0;
			int fpsCap = 0;
	};
}

#endif