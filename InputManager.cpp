#include "InputManager.h"

namespace ge {
	InputManager::~InputManager() {
		auto it = gameInputs.begin();
		while (it != gameInputs.end())
		{			
			it = gameInputs.erase(it);			
		}		
	}

	void InputManager::update(SDL_Event* event) {
		for (GameInput *input : gameInputs) {
			input->updateKeyInput(event);			
		}		
	}

	void InputManager::removeInput(GameInput* gi)
	{
		auto it = gameInputs.begin();
		while (it != gameInputs.end())
		{
			if (*it = gi)
			{			
				it = gameInputs.erase(it);
			}
			else
			{
				++it;
			}
		}		
	}

	void InputManager::addInput(GameInput* gi)
	{
		gameInputs.push_back(gi);
	}
}