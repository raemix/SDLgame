#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
class Game
{
	
	bool isRunning = true;
	SDL_Window* window;
	SDL_Texture* playerTex;
	SDL_Rect destR;

public:

	SDL_Renderer* renderer;
	Game();
	~Game();
	void init(const char* title, int xpos, int ypos, int width, int height, bool fullScreen);
	void handleEvents();
	void update();
	void render();
	void clean();
	bool running();

};