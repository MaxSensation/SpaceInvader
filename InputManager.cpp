#include "InputManager.h"

namespace ge {
	InputManager* InputManager::instance = 0;

	InputManager::~InputManager() {
		auto it = gameInputs.begin();
		while (it != gameInputs.end())
		{			
			it = gameInputs.erase(it);			
		}		
	}

	InputManager* InputManager::getInstance()
	{
		if (instance == 0)
		{
			instance = new InputManager();
		}
		return instance;
	}

	void InputManager::deleteInstance()
	{
		delete(instance);
		instance = NULL;
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