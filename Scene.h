#ifndef SCENE_H
#define SCENE_H

#include "Component.h"
#include <vector>

namespace ge{
	class Scene
	{
	public:		
		~Scene();
		void add(Component* component);
		std::vector<Component*> getComponents();
	private:
		std::vector<Component*> components;
	};
}

#endif