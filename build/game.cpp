#include "game.h"

SDL_Texture* playerTex;
Game::Game()
{
	isRunning = true;
}

Game::~Game()
{
}

void Game::Init(const char *title, int xPos, int yPos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
		printf("Subsystems initialized\n");
    }
    else
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
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

    window = SDL_CreateWindow( title, xPos, yPos, width, height, SDL_WINDOW_SHOWN );
    //if( window == NULL )
    //{
        printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        isRunning = false;
    //}

	renderer = SDL_CreateRenderer(window, -1, 0);
	if (renderer == 0)
	{
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		printf("Renderer created\n");
	}
	else
	{
		printf("Renderer creation failed\n");
		isRunning = false;
	}

	//SDL_Surface* tmpSurface = IMG_Load("/assets/face.png");
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
	printf("SDL Quit and Cleaned up\n");
}


