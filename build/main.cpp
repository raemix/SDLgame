#include "game.h"
#include <SDL.h>


Game* game = nullptr;

int main(int argc, char *argv[])
{

    const int fps = 60;
    const int frameDelay = 1000 / fps;

    Uint32 frameStart;
    int frameTime;


	game = new Game();

	game->Init("My SDL Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);


	while (game->Running())
	{
	    frameStart = SDL_GetTicks();

		game->HandleEvents();
		game->Update();
		game->Render();

		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
	}


	game->Clean();
	SDL_Delay(1000);
	return 0;
}
