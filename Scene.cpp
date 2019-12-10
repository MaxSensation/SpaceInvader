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

	void Scene::AddUpdatableObject(UpdateEachFrame* object)
	{
		UpdateEachFrames.push_back(object);
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

		for (UpdateEachFrame* object : UpdateEachFrames)
		{
			object->Update(delta);
		}

		SDL_RenderPresent(gameengine.GetRenderer());		
	}

	Scene::~Scene()
	{
	}	
}

