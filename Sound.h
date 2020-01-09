#include <SDL_audio.h>
#include <iostream>
#include <SDL_mixer.h>
#ifndef SOUND_H
#define SOUND_H

namespace ge {
	class Sound
	{
		public:
			~Sound();
			Sound(std::string filePath);
			void play();
		private:
			Mix_Chunk* sound;
	};
}
#endif // !SOUND_H