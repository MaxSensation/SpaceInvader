#ifndef GAMEINPUT_H
#define GAMEINPUT_H
#include <SDL.h>
#include "Component.h"

namespace ge{
	class GameInput : Component{
		public:			
			virtual void updateKeyInput(SDL_Event* event) = 0;
		protected:
			GameInput();
		private:
			GameInput(const GameInput&) = delete;
			const GameInput& operator=(const GameInput&) = delete;
	};
}

#endif
