#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "Scene.h"
#include "InputManager.h"
#include <SDL.h>
#include <vector>
#include <sstream> 

namespace ge {
	class GameEngine {	
	public:		
		void init(const char* title, int width, int height, const int targetFramerate);
		void launch();				
		void clearRender();		
		int* getScreenHeight();
		int* getScreenWidth();
		SDL_Renderer* getRenderer();
		InputManager* getInputManager();

		Scene* getScene();
		
		~GameEngine();
	private:
		bool initVideo();
		bool initWindow();
		bool initRenderer();
		bool initImage();
		bool initText();

		const char* title;
		int screenWidth = 0;
		int screenHeight = 0;		
		Uint32 targetFramerate = 0;
		bool bFPSCounter = false;
		float frameDelay = 0.0f;
		bool hasInitialised = false;

		SDL_Window* win = nullptr;
		SDL_Renderer* ren = nullptr;
		Scene* currentScene = nullptr;
		InputManager* inputManager = nullptr;
	};
	extern GameEngine gameengine;
}

#endif