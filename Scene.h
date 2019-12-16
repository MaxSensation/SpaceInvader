#ifndef SCENE_H
#define SCENE_H
#include "Sprite.h"
#include "UpdateEachFrame.h"
#include <vector>
#include "Text.h"

namespace ge{
	class Scene
	{
	public:		
		void addSprite(Sprite* sprite);
		void addText(Text* text);
		void addUpdatableObject(UpdateEachFrame* object);
		void removeSprite(Sprite* sprite);
		void update(float delta);
		~Scene();
	private:
		std::vector<Sprite*> sprites;	
		std::vector<Text*> texts;
		std::vector<UpdateEachFrame*> UpdateEachFrames;
	};
}

#endif