#include "GameEngine.h"
#include <SDL.h>
#include <iostream>

using namespace std;

namespace ge {	

	void GameEngine::Init(const char* title, int width, int height, const int targetFramerate) {
		screenWidth = &width;
		screenHeight = &height;
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

	void GameEngine::Render() {
		SDL_RenderClear(ren);
		SDL_SetRenderDrawColor(ren, 168, 230, 255, 255);
		currentScene->Render();
	}

	void GameEngine::Launch()
	{
		if (currentScene != nullptr)
		{
			bool running = true;
			while (running) {
				SDL_Event event;
				while (SDL_PollEvent(&event)) {
					switch (event.type) {
					case SDL_QUIT:
						running = false;
						break;
					}
				}
				Render();
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