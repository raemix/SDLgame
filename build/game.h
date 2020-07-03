#pragma once
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>



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
	bool isRunning = true;
	SDL_Window *window = nullptr;
	SDL_Renderer *renderer = nullptr;



};
