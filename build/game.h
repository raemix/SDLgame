#pragma once
#include <iostream>

#ifdef __linux__
#include <SDL2/SDL.h>
#elif WIN32_
#include <SDL.h>
#endif


class Game
{

public:
	Game();
	~Game();
	void Init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen);
	void HandleEvents();
	void Update();
	void Render();
	void Clean();
	bool Running() { return isRunning; }


private:
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;
	int count = 0;


};
