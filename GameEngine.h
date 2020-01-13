#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "Scene.h"
#include "InputManager.h"
#include "SoundManager.h"

#include <SDL.h>
#include <vector>
#include <sstream> 

namespace ge {
	class GameEngine {	
	public:		
		static GameEngine* getInstance();
		static void deleteInstance();
		void init(const char* title, int width, int height, const int targetFramerate);
		void launch();				
		void clearRender();		
		int* getScreenHeight();
		int* getScreenWidth();
		SDL_Renderer* getRenderer();
		InputManager* getInputManager();
		SoundManager* getSoundManager();		
		~GameEngine();
	private:
		static GameEngine* instance;
		bool initVideo();
		bool initAudio();
		bool initMixer();
		bool initWindow();
		bool initRenderer();
		bool initImage();
		bool initText();

		const char* title = "";
		int screenWidth = 0;
		int screenHeight = 0;		
		Uint32 targetFramerate = 0;
		bool bFPSCounter = false;
		float frameDelay = 0.0f;
		bool hasInitialised = false;

		SoundManager* soundManager = nullptr;
		SDL_Window* win = nullptr;
		SDL_Renderer* ren = nullptr;
		InputManager* inputManager = nullptr;		
	};
}

#endif