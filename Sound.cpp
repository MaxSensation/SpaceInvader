#include "Sound.h"
namespace ge{
	Sound::~Sound()
	{
		//Mix_FreeChunk(sound);
	}
	Sound::Sound(std::string filePath)
	{
		sound = Mix_LoadWAV(filePath.c_str());
	}

	void Sound::play() {
		Mix_PlayChannel(-1, sound, 0);
	}
}