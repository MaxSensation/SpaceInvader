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
			int SCREENWITDH = NULL;
			int SCREENHEIGHT = NULL;
	};
}

#endif