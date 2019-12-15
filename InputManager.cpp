#include "InputManager.h"

namespace ge {
	InputManager::InputManager()
	{

	}

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

	void InputManager::addInput(GameInput* gi)
	{
		gameInputs.push_back(gi);
	}
}