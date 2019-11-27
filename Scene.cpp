#include "Scene.h"
#include "Sprite.h"
#include <iostream>
#include <SDL.h>
#include "GameEngine.h"

namespace ge{
	void Scene::AddSprite(Sprite* sprite)
	{
		sprites.push_back(sprite);
	}

	void Scene::Render()
	{
		std::cout << *gameengine.GetScreenWidth() << std::endl;
		for (Sprite* sprite : sprites) {				
			SDL_RenderCopy(gameengine.GetRenderer(), sprite->GetTexture(), sprite->GetScreen(), sprite->GetSpriteRect());
			SDL_RenderPresent(gameengine.GetRenderer());
		}
	}

	Scene::~Scene()
	{
	}
}

