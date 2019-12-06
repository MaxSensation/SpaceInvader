#include "Game.h"

using namespace ge;

Game::Game():	
	scene(new Scene),
	SCREENWITDH(600),
	SCREENHEIGHT(600)
{	
	gameengine.Init("SpaceInvader", SCREENWITDH, SCREENHEIGHT, 60);	
	player = new Player(&SCREENWITDH, &SCREENHEIGHT, scene);
	scene->AddSprite(player);
	gameengine.SetScene(scene);	
	gameengine.Launch();
}

Game::~Game()
{	
	player = nullptr;
	delete(player);
	scene = nullptr;
	delete(scene);
}

int main(int argc, char** argv)
{
	Game game;
	return 0;
}