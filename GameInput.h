#include <SDL.h>
#ifndef GAMEINPUT_H
#define GAMEINPUT_H

namespace ge{
	class GameInput {
		public:
			GameInput();
			~GameInput();
			virtual void UpdateKeyInput(SDL_Event* event) = 0;
		private:						
	};
}

#endif
