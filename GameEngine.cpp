#include "GameEngine.h"
#include <SDL.h>
#include <iostream>
#include <vector>
#include <chrono>
#include <SDL_image.h>

using namespace std;

namespace ge {	

	void GameEngine::Init(const char* title, int width, int height, const int targetFramerate){
		screenWidth = width;
		screenHeight = height;
		fps = targetFramerate;
		frameDelay = 1000.0f/fps;
		bool success = true;
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{	
			win = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL);
			Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
			ren = SDL_CreateRenderer(win, -1, render_flags);
			if (win == NULL)
			{
				printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{			
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
				else
				{
					gScreenSurface = SDL_GetWindowSurface(win);
				}
			}
		}
	}

	void GameEngine::SetScene(Scene* scene)
	{
		currentScene = scene;
	}

	SDL_Renderer* GameEngine::GetRenderer()
	{
		return ren;
	}

	SDL_Surface* GameEngine::GetScreenSurface() {
		return gScreenSurface;
	}

	InputManager* GameEngine::GetInputManager() {
		return inputManager;
	}

	void GameEngine::ClearRender() {
		SDL_RenderClear(ren);
		SDL_SetRenderDrawColor(ren, 0, 0, 0, 0);		
	}

	void GameEngine::Launch()
	{				
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
				ClearRender();
				while (SDL_PollEvent(&event)) {
					inputManager->UpdateKeyDown(&event);
					switch (event.type) {	
						case SDL_QUIT:
							running = false;
							break;
					}
				}					
				currentScene->Update(delta);
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

	void GameEngine::Update()
	{
	}

	int* GameEngine::GetScreenHeight() {
		return &screenHeight;
	}

	int* GameEngine::GetScreenWidth() {
		return &screenWidth;
	}

	GameEngine::~GameEngine() {
		SDL_DestroyRenderer(ren);
		SDL_DestroyWindow(win);
		currentScene = nullptr;
		delete(currentScene);
		inputManager = nullptr;
		delete(inputManager);
		SDL_Quit();				
	}

	GameEngine gameengine;
}