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
		SDL_Surface* GetScreenSurface();
		InputManager* GetInputManager();
		void ClearRender();		
		int* GetScreenHeight();
		int* GetScreenWidth();
	private:
		void Update();
		SDL_Window* win = nullptr;
		SDL_Renderer* ren = nullptr;
		SDL_Surface* gScreenSurface = nullptr;
		Scene* currentScene = nullptr;
		InputManager* inputManager = nullptr;
		int screenWidth = 0;
		int screenHeight = 0;		
		Uint32 fps = 0;
		bool bFPSCounter = false;
		float frameDelay = 0.0f;
		bool hasInitialised = false;
	};
	extern GameEngine gameengine;
}

#endif