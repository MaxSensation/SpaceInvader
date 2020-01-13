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
		static Scene* getInstance();
		static void deleteInstance();
		void addSprite(Sprite* sprite);
		void removeSprite(Sprite* sprite);
		void addText(Text* text);
		void addUpdatableObject(UpdateEachFrame* object);
		void update(float delta);				
	private:	
		static Scene* instance;
		~Scene();		
		Scene();
		std::vector<Sprite*> sprites;	
		std::vector<Text*> texts;
		std::vector<UpdateEachFrame*> UpdateEachFrames;
	};	
}

#endif