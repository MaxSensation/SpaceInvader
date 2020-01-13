#include "GameInput.h"
#include "GameEngine.h"
#include <iostream>

namespace ge{
	GameInput::GameInput()		
	{	
		GameEngine::getInstance()->getInputManager()->addInput(this);
	}
}