#include "Scene.h"

namespace ge{
	Scene::~Scene()
	{
	}
	
	void Scene::add(Component* component) {
		components.push_back(component);
	}

	std::vector<Component*> Scene::getComponents() {
		return components;
	}
}

