#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <SDL.h>
#include <vector>
#include "GameInput.h"

namespace ge{

	class InputManager
	{
		public:
			InputManager();
			void UpdateKeyDown(SDL_Event* event);	
			void AddGameInput(GameInput* gi);
		private:
			std::vector<GameInput*> gameInputs;
	};
}

#endif