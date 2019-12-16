#include "Scene.h"
#include <iostream>
#include <set>
#include <SDL.h>
#include "GameEngine.h"

namespace ge{
	void Scene::addSprite(Sprite* sprite)
	{
		sprites.push_back(sprite);
	}

	void Scene::addText(Text* text)
	{
		texts.push_back(text);
	}

	void Scene::addUpdatableObject(UpdateEachFrame* object)
	{
		UpdateEachFrames.push_back(object);
	}

	void Scene::removeSprite(Sprite* sprite)
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


	void Scene::update(float delta)
	{
		for (Sprite* sprite : sprites) {										
			sprite->update(delta);
			sprite->updatePos();
			sprite->render();
		}

		for (UpdateEachFrame* object : UpdateEachFrames)
		{
			object->update(delta);
		}

		for (Text* text : texts) {
			text->render();
		}

		SDL_RenderPresent(gameengine.getRenderer());		
	}

	Scene::~Scene()
	{
	}	
}

