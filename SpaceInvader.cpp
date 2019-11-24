#include "GameEngine.h"
#include "Scene.h"

using namespace ge;

int main(int argc, char** argv)
{		
	Scene* scene = new Scene();
	gameengine.run(scene);
	delete(scene);
	return 0;
}