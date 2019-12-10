#include "LaserHandler.h"

namespace ge {
	LaserHandler::LaserHandler()
	{	
	}
	void LaserHandler::Init(Scene* scene)
	{		
		handlerScene = scene;		
	}
	LaserHandler::~LaserHandler()
	{		
		for (LaserBeam* laser : laserBeams) {
			RemoveLaserBeam(laser);
		}
	}

	void LaserHandler::AddLaser(LaserBeam* laser)
	{
		laserBeams.push_back(laser);
		handlerScene->AddSprite(laser);
	}

	void LaserHandler::CheckLaserBeams() {
		for (LaserBeam* laser : laserBeams) {
			if (laser->OutsideBounce())
			{
				RemoveLaserBeam(laser);
			}
		}
	}

	void LaserHandler::RemoveLaserBeam(LaserBeam* laser) {
		handlerScene->RemoveSprite(laser);
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

	bool LaserHandler::CheckCollition(SDL_Rect* object) {				
		for (LaserBeam* laser : laserBeams)
		{
			if (SDL_HasIntersection(object, laser->GetSpriteRect()))
			{
				RemoveLaserBeam(laser);
				return true;
			}
			else
			{
				return false;
			}
		}
		return false;
	}

	void LaserHandler::Update(float delta)
	{
		CheckLaserBeams();
	}
	LaserHandler laserHandler;
}