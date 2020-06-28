#include "game.h"
#include <SDL2/SDL.h>


Game* game = nullptr;

int main(int argc, char *argv[])
{
	game = new Game();

	game->Init("My SDL Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);


	while (game->Running())
	{
		game->HandleEvents();
		game->Update();
		game->Render();

	}


	game->Clean();
	SDL_Delay(1000);
	return 0;
}
