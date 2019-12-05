#include "GameInput.h"
#include "GameEngine.h"
#include <iostream>

namespace ge{
	GameInput::GameInput()		
	{	
		gameengine.GetInputManager()->AddGameInput(this);
	}

	GameInput::~GameInput()
	{		
	}
}