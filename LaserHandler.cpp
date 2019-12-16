#include "LaserHandler.h"

namespace ge {
	LaserHandler::LaserHandler()
	{	
	}
	void LaserHandler::init(Scene* scene)
	{		
		handlerScene = scene;		
	}
	LaserHandler::~LaserHandler()
	{		
		for (LaserBeam* laser : laserBeams) {
			removeLaserBeam(laser);
		}
	}

	void LaserHandler::addLaser(LaserBeam* laser)
	{
		laserBeams.push_back(laser);
		handlerScene->addSprite(laser);
	}

	void LaserHandler::checkLaserBeams() {
		for (LaserBeam* laser : laserBeams) {
			if (laser->outsideBounce())
			{
				removeLaserBeam(laser);
			}
		}
	}

	void LaserHandler::removeLaserBeam(LaserBeam* laser) {
		handlerScene->removeSprite(laser);
		auto it = laserBeams.begin();
		while (it != laserBeams.end())
		{
			if (*it == laser) {
				it = laserBeams.erase(it);
				std::cout << "LaserBeam Removed" << std::endl;
			}
			else {
				++it;
			}
		}
	}

	bool LaserHandler::checkCollision(SDL_Rect* object) {
		for (LaserBeam *laser : laserBeams)
		{
			if (checkRectCollision(*object, *laser->getSpriteRect()))
			{
				removeLaserBeam(laser);
				return true;
			}
		}
		return false;
	}

	void LaserHandler::update(float delta)
	{
		checkLaserBeams();
	}
	LaserHandler laserHandler;
}