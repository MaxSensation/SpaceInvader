#include <iostream>
#include <SDL.h>

int main(int argc, char *argv[])
{
	if (SDL_Init(SDL_INIT_EVERYTHING)) {
		std::cout << "SDL chould not initialise! SDL Error: " << SDL_GetError << std::endl;		
	}
	return EXIT_SUCCESS;
}