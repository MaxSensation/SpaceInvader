#include "GameEngine.h"
#include <SDL.h>
#include <iostream>
#include <vector>

using namespace std;

namespace ge {	

	void GameEngine::Init(const char* title, int width, int height, const int targetFramerate){
		screenWidth = &width;
		screenHeight = &height;
		fps = targetFramerate;
		SDL_Init(SDL_INIT_VIDEO);
		win = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);
		ren = SDL_CreateRenderer(win, -1, 0);		
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

	void GameEngine::Render() {
		SDL_RenderClear(ren);
		SDL_SetRenderDrawColor(ren, 0, 0, 0, 0);
		currentScene->Render();
	}

	void GameEngine::Launch()
	{		
		if (currentScene != nullptr)
		{
			bool running = true;			
			Uint32 startTime = 0;
			Uint32 endTime = 0;
			Uint32 delta = 0;
			Uint32 timePerFrame = 1000/fps;
			short currentFPS = 60;			
			while (running) {				
				if (!startTime) {
					startTime = SDL_GetTicks();
				}
				else {
					delta = endTime - startTime;
				}

				SDL_Event event;
				while (SDL_PollEvent(&event)) {
					inputManager->UpdateKeyDown(&event);
					switch (event.type) {					
						case SDL_QUIT:
							running = false;
							break;
					}
				}
				
				Render();			
				
				if (delta < timePerFrame) {
					SDL_Delay(timePerFrame - delta);
				}							
				if (delta > timePerFrame) {
					currentFPS = 1000 / delta;
				}										
				startTime = endTime;
				endTime = SDL_GetTicks();
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