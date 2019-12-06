#include "Scene.h"
#include <iostream>
#include <set>
#include <SDL.h>
#include "GameEngine.h"

namespace ge{
	void Scene::AddSprite(Sprite* sprite)
	{
		sprites.push_back(sprite);
	}
	void Scene::RemoveSprite(Sprite* sprite)
	{
		auto it = sprites.begin();
		while (it != sprites.end())
		{
			if (*it == sprite) {				
				it = sprites.erase(it);
			}			
			else {
				++it;
			}
		}
	}


	void Scene::Update(float delta)
	{
		for (Sprite* sprite : sprites) {										
			sprite->Update(delta);
			sprite->UpdatePos();
			sprite->Render();
		}
		SDL_RenderPresent(gameengine.GetRenderer());		
	}

	Scene::~Scene()
	{
	}	
}

