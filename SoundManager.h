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
			~SoundManager();
			void setMusic(std::string audioFile);
			void playMusic();
			void stopMusic();
			Sound* createSound(std::string audioFile);
			void deleteSound(Sound* sound);
		private:
			std::vector<Sound*> sounds;			
			Mix_Music* music = nullptr;
	};
}
#endif SOUNDMANAGER_H
