#ifndef SCENE_H
#define SCENE_H
#include "Sprite.h"
#include "UpdateEachFrame.h"
#include <vector>

namespace ge{
	class Scene
	{
	public:		
		void addSprite(Sprite* sprite);
		void addUpdatableObject(UpdateEachFrame* object);
		void removeSprite(Sprite* sprite);
		void update(float delta);
		~Scene();
	private:
		std::vector<Sprite*> sprites;		
		std::vector<UpdateEachFrame*> UpdateEachFrames;
	};
}

#endif