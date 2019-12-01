#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include "Scene.h"
#include <SDL.h>
#include <vector>

namespace ge {
	class GameEngine {	
	public:
		~GameEngine();
		void SetScene(Scene* scene);
		void Init(const char* title, int width, int height, const int targetFramerate);
		void Launch();
		SDL_Renderer* GetRenderer();
		void Render();
		int* GetScreenHeight();
		int* GetScreenWidth();
	private:		
		void Update();
		SDL_Window* win = nullptr;
		SDL_Renderer* ren = nullptr;
		Scene* currentScene = nullptr;
		int* screenWidth = nullptr;
		int* screenHeight = nullptr;
		short fps = 60;
		bool hasInitialised = false;
	};
	extern GameEngine gameengine;
}

#endif