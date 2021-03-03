#pragma once
#include "Game.h"

class GameObject
{
	int xpos = 0;
	int ypos = 0;
	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
	


public:
	GameObject(const char* textureSheet, int x, int y);
	~GameObject();

	void Update();
	void Render();

};