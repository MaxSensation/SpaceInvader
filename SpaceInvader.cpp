#include "GameEngine.h"
#include <iostream>


using namespace ge;
using namespace std;

MovingSprite* player = nullptr;

void MovePlayerRight() {
	player -> Translate(1, 0);
}

int main(int argc, char** argv)
{
	gameengine.Init("SpaceInvader", 500, 500, 60);
	Scene* scene = new Scene();
	player = new MovingSprite("Player", 225, 425, 50, 50, "Player.bmp");
	SDL_Keycode test;
	//gameengine.AddKeyDown(test, MovePlayerRight);
	scene->AddSprite(player);
	gameengine.SetScene(scene);
	gameengine.Launch();
	delete(player);
	delete(scene);	
	return 0;
}