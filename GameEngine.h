#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "Scene.h"
#include "InputManager.h"
#include <SDL.h>
#include <vector>

namespace ge {
	class GameEngine {	
	public:
		GameEngine() : inputManager(new InputManager) {};
		~GameEngine();
		void SetScene(Scene* scene);
		void Init(const char* title, int width, int height, const int targetFramerate);
		void Launch();
		SDL_Renderer* GetRenderer();
		InputManager* GetInputManager();
		void Render();
		int* GetScreenHeight();
		int* GetScreenWidth();
	private:		
		void Update();
		SDL_Window* win = nullptr;
		SDL_Renderer* ren = nullptr;
		Scene* currentScene = nullptr;
		InputManager* inputManager = nullptr;
		int* screenWidth = nullptr;
		int* screenHeight = nullptr;		
		short fps = 0;
		bool hasInitialised = false;
	};
	extern GameEngine gameengine;
}

#endif