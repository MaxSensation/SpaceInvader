#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <SDL.h>
#include <vector>
#include "GameInput.h"

namespace ge{

	class InputManager
	{
		public:			
			static InputManager* getInstance();
			static void deleteInstance();
			void update(SDL_Event* event);
			void removeInput(GameInput* gi);
			void addInput(GameInput* gi);
		private:
			static InputManager* instance;
			InputManager(){};
			~InputManager();
			std::vector<GameInput*> gameInputs;
			const InputManager& operator=(const InputManager&) = delete;
	};
}

#endif