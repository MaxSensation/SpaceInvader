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
			~InputManager();
			void update(SDL_Event* event);	
			void addInput(GameInput* gi);
		private:
			std::vector<GameInput*> gameInputs;
	};
}

#endif