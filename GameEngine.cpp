#include "GameEngine.h"
#include <SDL.h>
#include <iostream>
#include <vector>
#include <chrono>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

using namespace std;

namespace ge {	
	GameEngine* GameEngine::instance = 0;

	GameEngine::GameEngine(const char* title, int width, int height, const int targetFramerate) :
		title(title),
		screenWidth(width),
		screenHeight(height),
		targetFramerate(targetFramerate)

	{		
		frameDelay = 1000.0f / targetFramerate;
		if (initVideo())
			if (initAudio())
				if (initMixer())
					if (initWindow())
						if (initRenderer())
							if (initImage())
								if (initText())
								{
									hasInitialised = true;
								}
								else
									printf("SDL Text could not initialize! SDL Text Error: %s\n", SDL_GetError());
							else
								printf("SDL Image could not initialize! SDL Image Error: %s\n", IMG_GetError());
						else
							printf("SDL Renderer could not initialize! SDL Renderer Error: %s\n", SDL_GetError());
					else
						printf("SDL Window could not initialize! SDL Window Error: %s\n", SDL_GetError());
				else
					printf("SDL Mixer could not initialize! SDL Mixer Error: %s\n", SDL_GetError());
			else
				printf("SDL Audio could not initialize! SDL Audio Error: %s\n", SDL_GetError());
		else
			printf("SDL Video could not initialize! SDL Video Error: %s\n", SDL_GetError());
	}

	bool GameEngine::initVideo()
	{
		if (SDL_Init(SDL_INIT_VIDEO) == 0)
			return true;
		else
			return false;
	}

	bool GameEngine::initAudio()
	{		
		if (SDL_Init(SDL_INIT_AUDIO) == 0)
			return true;
		else
			return false;
	}

	bool GameEngine::initMixer()
	{
		if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == 0)
			return true;
		else
			return false;
	}	

	bool GameEngine::initWindow()
	{
		win = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_OPENGL);
		
		if (win != NULL)
			return true;
		else
			return false;
	}

	bool GameEngine::initRenderer()
	{
		Uint32 render_flags = SDL_RENDERER_ACCELERATED;
		ren = SDL_CreateRenderer(win, -1, render_flags);
	
		if (ren != NULL)		
			return true;
		else
			return false;
	}

	bool GameEngine::initImage()
	{
		int imgFlags = IMG_INIT_PNG;
		if (IMG_Init(imgFlags) & imgFlags)
		{			
			return true;
		}
		else		
			return false;			
	}

	bool GameEngine::initText() {
		if (TTF_Init() == 0)
		{
			return true;
		}
		return false;
	}

	GameEngine* GameEngine::getInstance(const char* title, int width, int height, const int targetFramerate)
	{
		if (instance == 0)
		{
			instance = new GameEngine(title, width, height, targetFramerate);
		}
		return instance;
	}

	GameEngine* GameEngine::getInstance()
	{				
		return instance;
	}

	void GameEngine::deleteInstance()
	{
		delete instance;
		instance = NULL;
	}

	SDL_Renderer* GameEngine::getRenderer()
	{
		return ren;
	}

	InputManager* GameEngine::getInputManager() {
		return InputManager::getInstance();
	}

	SoundManager* GameEngine::getSoundManager()
	{
		return SoundManager::getInstance();
	}

	void GameEngine::clearRender() {
		SDL_RenderClear(ren);
		SDL_SetRenderDrawColor(ren, 0, 0, 0, 0);		
	}

	void GameEngine::launch()
	{		
		if (hasInitialised) {					
			bool running = true;
			Uint32 frameStart = 0.0f;;
			Uint32 frameTime = 0.0f;;
			float delta = 0.0f;
			short currentFPS = 0;
			SDL_Event event;
			while (running) {
				frameStart = SDL_GetTicks();
					
				clearRender();
				while (SDL_PollEvent(&event)) {
					InputManager::getInstance()->update(&event);
					switch (event.type) {
					case SDL_QUIT:
						running = false;
						break;
					}
				}										
				frameTime = SDL_GetTicks() - frameStart;
				delta = frameDelay - frameTime;
				Scene::getInstance()->update(delta);
				if (bFPSCounter && delta != 0)
				{
					currentFPS = 1000 / delta;
					cout << "FPS: " << currentFPS << endl;
				}
				if (frameDelay > frameTime)
				{
					SDL_Delay(delta);
				}
			}
			}
		else
		{
			cout << "Error: Need to use init(title, screenWidth, screenHeight, targetFramerate)" << endl;
		}
	}

	int* GameEngine::getScreenHeight() {
		return &screenHeight;
	}

	int* GameEngine::getScreenWidth() {
		return &screenWidth;
	}

	GameEngine::~GameEngine() {
		SoundManager::deleteInstance();
		InputManager::deleteInstance();
		Scene::deleteInstance();
		Mix_Quit();
		TTF_Quit();
		IMG_Quit();
		SDL_DestroyRenderer(ren);
		SDL_DestroyWindow(win);
		SDL_Quit();								
	}
}