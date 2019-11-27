#include "GameEngine.h"
#include <iostream>


using namespace ge;
using namespace std;

int main(int argc, char** argv)
{
	gameengine.Init("Test", 1000, 1000, 60);
	Scene* scene = new Scene();
	Sprite* player = new Sprite("Player", 0, 0, 739, 853, "Player.bmp");
	scene->AddSprite(player);		
	gameengine.SetScene(scene);
	gameengine.Launch();

	delete(player);
	delete(scene);	
	return 0;
}