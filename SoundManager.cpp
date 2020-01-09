#include "SoundManager.h"

namespace ge{
	SoundManager::~SoundManager()
	{
		auto soundIT = sounds.begin();
		while (soundIT != sounds.end())
		{
			delete(*soundIT);
			sounds.erase(soundIT);
		}
		Mix_FreeMusic(music);
		music = nullptr;
		delete(music);
	}

	void SoundManager::setMusic(std::string audioFile) {
		music = Mix_LoadMUS(audioFile.c_str());
		Mix_VolumeMusic(MIX_MAX_VOLUME/2);
	}

	void SoundManager::playMusic()
	{		
		if (Mix_PlayingMusic() == 0)
		{			
			Mix_PlayMusic(music, -1);
		}
		else
		{			
			if (Mix_PausedMusic() == 1)
			{				
				Mix_ResumeMusic();
			}
		}
	}

	void SoundManager::stopMusic()
	{
		Mix_HaltMusic();
	}

	Sound* SoundManager::createSound(std::string audioFile)
	{
		sounds.push_back(new Sound(audioFile));
		return sounds.back();		
	}
	void SoundManager::deleteSound(Sound* sound)
	{
		auto soundIT = sounds.begin();
		while (soundIT != sounds.end())
		{
			if (sound == *soundIT)
			{
				delete(*soundIT);
				sounds.erase(soundIT);
			}
			else
			{
				++soundIT;
			}
		}
	}
}