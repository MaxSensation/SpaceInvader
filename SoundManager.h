#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H
#include "Sound.h"
#include <iostream>
#include <vector>
#include <SDL_mixer.h>

namespace ge{
class SoundManager
	{
		public:		
			static SoundManager* getInstance();
			static void deleteInstance();
			void setMusic(std::string audioFile);
			void playMusic();
			void stopMusic();
			Sound* createSound(std::string audioFile);			
		private:
			static SoundManager* instance;
			SoundManager();
			~SoundManager();
			std::vector<Sound*> sounds;			
			Mix_Music* music = nullptr;
			const SoundManager& operator=(const SoundManager&) = delete;
	};
}
#endif SOUNDMANAGER_H
