#pragma once
#include <iostream>
#include <SDL2/SDL.h>



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
