#include "GameInput.h"
#include "GameEngine.h"
#include <iostream>

namespace ge{
	GameInput::GameInput()		
	{	
		gameengine.getInputManager()->addInput(this);
	}
}