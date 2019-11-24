#include "GameEngine.h"
#include "Scene.h"
#include "Component.h"
#include <SDL.h>

namespace ge {
	GameEngine::GameEngine() {
		SDL_Init(SDL_INIT_EVERYTHING);
		win = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, 0);
		ren = SDL_CreateRenderer(win, -1, 0);		
	}

	GameEngine::~GameEngine() {
		SDL_DestroyRenderer(ren);
		SDL_DestroyWindow(win);		
		SDL_Quit();
	}

	SDL_Renderer* GameEngine::get_ren() const {
		return ren;
	}

	void GameEngine::run(Scene* scene)
	{
		bool running = true;
		while (running) {
			SDL_Event event;
			while (SDL_PollEvent(&event)) {
				switch (event.type){
				case SDL_QUIT: 
					running = false;
					break;
				}
			}
			for (Component* c : scene -> getComponents())
				c -> draw();
		}
	}

	GameEngine gameengine;
}