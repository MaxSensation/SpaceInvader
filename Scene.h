#ifndef SCENE_H
#define SCENE_H
#include "Sprite.h"
#include <vector>

namespace ge{
	class Scene
	{
	public:		
		void AddSprite(Sprite* sprite);
		void Render();
		~Scene();
	private:
		std::vector<Sprite*> sprites;
	};
}

#endif