#pragma once
#include "Game.h"

class GameObject
{
	int xpos = 0;
	int ypos = 0;
	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
	SDL_Renderer* renderer;


public:
	GameObject(const char* textureSheet, SDL_Renderer* ren, int x, int y);
	~GameObject();

	void Update();
	void Render();

};