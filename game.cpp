#include "game.h"

Game::Game()
{
	isRunning = true;
}

Game::~Game()
{
}

void Game::Init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystems initialized" << std::endl;
	}
	else
	{
		std::cout << "SDL Init Failed" << std::endl;
		isRunning = false;
	}
	
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}
	else
	{
		flags = SDL_WINDOW_SHOWN;
	}
	SDL_CreateWindow(title, xPos, yPos, width, height, flags);
	
	if (window == 0)
	{
		std::cout << "Window created" << std::endl;
	} else
	{
		std::cout << "Creation of window failed" << std::endl;
		isRunning = false;
	}

	renderer = SDL_CreateRenderer(window, -1, 0);
	if (renderer == 0)
	{
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		std::cout << "Renderer created" << std::endl;
	}
	else
	{
		std::cout << "Renderer creation failed" << std::endl;
		isRunning = false;
	}
}

void Game::HandleEvents()
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

void Game::Update()
{
	count++;
	std::cout << count << std::endl;
}

void Game::Render()
{
	SDL_RenderClear(renderer);
	//add stuff to render
	SDL_RenderPresent(renderer);
}

void Game::Clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "SDL Quit and Cleaned up" << std::endl;
}


