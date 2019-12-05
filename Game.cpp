#include "Game.h"

using namespace ge;

Game::Game():	
	scene(new Scene),
	SCREENWITDH(500),
	SCREENHEIGHT(500)
{	
	gameengine.Init("SpaceInvader", SCREENWITDH, SCREENHEIGHT, 60);
	player = new Player("Player", (SCREENWITDH / 2) - (50 / 2), SCREENHEIGHT - (50 + 10), 50, 50, "Player.bmp");			
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