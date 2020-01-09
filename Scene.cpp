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

	void Scene::update(float delta)
	{		
		for (UpdateEachFrame* object : UpdateEachFrames)
		{
			object->update(delta);
		}

		for (Sprite* sprite : sprites) {						
			sprite->update(delta);
			sprite->updatePos();			
			sprite->render();			
		}

		auto sprite = sprites.begin();
		while (sprite != sprites.end())
		{
			if ((*sprite)->isDestroyd()) {
				delete(*sprite);
				sprite = sprites.erase(sprite);
			}
			else {
				++sprite;
			}
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

