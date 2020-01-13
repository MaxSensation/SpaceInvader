#include "Scene.h"
#include <iostream>
#include <set>
#include <SDL.h>
#include "GameEngine.h"


namespace ge{
	Scene* Scene::instance = 0;
	
	Scene* Scene::getInstance()
	{
		if (instance == 0)
		{
			instance = new Scene();
		}
		return instance;
	}	
	
	void Scene::deleteInstance()
	{
		delete instance;
		instance = NULL;
	}

	void Scene::addSprite(Sprite* sprite)
	{
		sprites.push_back(sprite);
	}

	void Scene::removeSprite(Sprite* sprite)
	{
		auto it = sprites.begin();
		while (it != sprites.end())
		{
			if ((*it)==sprite) {						
				it = sprites.erase(it);			
			}
			else {
				++it;
			}
		}
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
			if (sprite->getImgDest() != 0)
			{
				sprite->update(delta);
				sprite->updatePos();
				sprite->render();
			}			
		}		

		for (Text* text : texts) {
			text->render();
		}

		SDL_RenderPresent(GameEngine::getInstance()->getRenderer());
	}

	Scene::~Scene()
	{

	}

	Scene::Scene()
	{

	}
}

