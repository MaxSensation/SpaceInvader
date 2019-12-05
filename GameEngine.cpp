#include "GameEngine.h"
#include <SDL.h>
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

namespace ge {	

	void GameEngine::Init(const char* title, int width, int height, const int targetFramerate){
		screenWidth = &width;
		screenHeight = &height;
		fps = targetFramerate;
		frameDelay = 1000.0f/fps;
		SDL_Init(SDL_INIT_VIDEO);
		win = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL);
		ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	}

	void GameEngine::SetScene(Scene* scene)
	{
		currentScene = scene;
	}

	SDL_Renderer* GameEngine::GetRenderer()
	{
		return ren;
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
				if (delta != 0)
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
		return screenHeight;
	}

	int* GameEngine::GetScreenWidth() {
		return screenWidth;
	}

	GameEngine::~GameEngine() {
		SDL_DestroyRenderer(ren);
		SDL_DestroyWindow(win);
		currentScene = nullptr;
		delete(currentScene);		
		SDL_Quit();				
	}

	GameEngine gameengine;
}