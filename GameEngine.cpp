#include "GameEngine.h"
#include <SDL.h>
#include <iostream>
#include <vector>
#include <chrono>
#include <SDL_image.h>
#include <SDL_ttf.h>

using namespace std;

namespace ge {	

	bool GameEngine::initVideo()
	{
		if (SDL_Init(SDL_INIT_VIDEO) == 0)
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

	void GameEngine::init(const char* title, int screenWidth, int screenHeight, const int targetFramerate) {
		this->title = title;
		this->screenWidth = screenWidth;
		this->screenHeight = screenHeight;
		this->targetFramerate = targetFramerate;
		frameDelay = 1000.0f / targetFramerate;
		inputManager = new InputManager();
		currentScene = new Scene();
		
		if (initVideo())
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
			printf("SDL Video could not initialize! SDL Video Error: %s\n", SDL_GetError());
	}

	SDL_Renderer* GameEngine::getRenderer()
	{
		return ren;
	}

	InputManager* GameEngine::getInputManager() {
		return inputManager;
	}

	Scene* GameEngine::getScene() {
		return currentScene;
	}

	void GameEngine::clearRender() {
		SDL_RenderClear(ren);
		SDL_SetRenderDrawColor(ren, 0, 0, 0, 0);		
	}

	void GameEngine::launch()
	{		
		if (hasInitialised) {
			if (currentScene != nullptr)
			{
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
						inputManager->update(&event);
						switch (event.type) {
						case SDL_QUIT:
							running = false;
							break;
						}
					}
					currentScene->update(delta);
					
					frameTime = SDL_GetTicks() - frameStart;
					delta = frameDelay - frameTime;
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
				cout << "Error: No scene is selected! please use SetScene()" << endl;
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
		delete(inputManager);
		delete(currentScene);
		TTF_Quit();
		IMG_Quit();
		SDL_DestroyRenderer(ren);
		SDL_DestroyWindow(win);
		SDL_Quit();								
	}
	GameEngine gameengine;
}