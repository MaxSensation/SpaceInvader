#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include <SDL.h>
#include "Scene.h"

namespace ge {
	class GameEngine {
	public:
		GameEngine();
		~GameEngine();
		SDL_Renderer* get_ren() const;
		void run(Scene* scene);
	private:
		SDL_Window* win;
		SDL_Renderer* ren;
	};
	extern GameEngine gameengine;
}

#endif