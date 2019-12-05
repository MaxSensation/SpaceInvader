#include "InputManager.h"

namespace ge {
	InputManager::InputManager()
	{

	}

	void InputManager::UpdateKeyDown(SDL_Event* event) {
		for (GameInput *input : gameInputs) {
			input->UpdateKeyInput(event);
		}
	}

	void InputManager::AddGameInput(GameInput* gi)
	{
		gameInputs.push_back(gi);
	}
}