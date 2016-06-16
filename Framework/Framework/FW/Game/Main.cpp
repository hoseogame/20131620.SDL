#include "Game.h"

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

int main(int argc, char* args[])
{
	Uint32 frameStart, frameTime;

	TheGame->init("SDL_Game_Create", 100, 100, 1280, 720, false);

	while (TheGame->running())
	{
		frameStart = SDL_GetTicks();

		TheGame->handleEvents();
		TheGame->update();
		TheGame->render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameTime< DELAY_TIME)
		{
			SDL_Delay((int)(DELAY_TIME - frameTime));
		}
	}
	TheGame->clean();
	return 0;
}