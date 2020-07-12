#include "Game.h"

Game::Game()
{}
Game::~Game()
{}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullScreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL Initialized" << std::endl;
	}
	else
	{
		std::cout << "SDL Failed to Initialize" << std::endl;
		std::cout << SDL_GetError();
		isRunning = false;
	}

	int flags = SDL_WINDOW_SHOWN;
	if (fullScreen)
		flags = SDL_WINDOW_FULLSCREEN;

	window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
	if (window)
	{
			std::cout << "Window Created" << std::endl;
	}
	else
	{
		std::cout << "Window failed to create" << std::endl;
		std::cout << SDL_GetError() << std::endl;
		isRunning = false;
	}

	renderer = SDL_CreateRenderer(window, -1, 0);
	if (renderer)
	{
		SDL_SetRenderDrawColor(renderer, 127, 127, 127, drawAlpha);
		std::cout << "Renderer created" << std::endl;
	}
	else
	{
		std::cout << "Renderer failed to create" << std::endl;
		std::cout << SDL_GetError() << std::endl;
		isRunning = false;
	}
}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;

	default:
		break;
	}
}

void Game::update()
{
	

}

void Game::render()
{
	SDL_RenderClear(renderer);

	// this is where we add stuff to render

	SDL_RenderPresent(renderer);
}

bool Game::running()
{
	return isRunning;
}


void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned." << std::endl;
}
