#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "Scene.h"
#include "InputManager.h"
#include <SDL.h>
#include <vector>

namespace ge {
	class GameEngine {	
	public:		
		void init(const char* title, int width, int height, const int targetFramerate);
		void setScene(Scene* scene);
		void launch();				
		void clearRender();		
		int* getScreenHeight();
		int* getScreenWidth();
		SDL_Renderer* getRenderer();
		SDL_Surface* getScreenSurface();
		InputManager* getInputManager();
		
		~GameEngine();
	private:
		bool initVideo();
		bool initWindow();
		bool initRenderer();
		bool initImage();

		const char* title;
		int screenWidth = 0;
		int screenHeight = 0;		
		Uint32 targetFramerate = 0;
		bool bFPSCounter = false;
		float frameDelay = 0.0f;
		bool hasInitialised = false;

		SDL_Window* win = nullptr;
		SDL_Renderer* ren = nullptr;
		SDL_Surface* gScreenSurface = nullptr;
		Scene* currentScene = nullptr;
		InputManager* inputManager = new InputManager;
	};
	extern GameEngine gameengine;
}

#endif