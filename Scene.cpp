#include "Scene.h"
#include "Sprite.h"
#include "MovingSprite.h"
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
		for (Sprite* sprite : sprites) {							
			SDL_RenderCopy(gameengine.GetRenderer(), sprite->GetTexture(), sprite->GetScreen(), sprite->GetSpriteRect());			
		}
		SDL_RenderPresent(gameengine.GetRenderer());
	}

	Scene::~Scene()
	{
	}
}

