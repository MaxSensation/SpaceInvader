#ifndef SCENE_H
#define SCENE_H
#include "Sprite.h"
#include "MovingSprite.h"
#include <vector>

namespace ge{
	class Scene
	{
	public:		
		void AddSprite(Sprite* sprite);
		void RemoveSprite(Sprite* sprite);
		void Update(float delta);
		~Scene();
	private:
		std::vector<Sprite*> sprites;		
	};
}

#endif