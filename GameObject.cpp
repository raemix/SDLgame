#include "GameObject.h"
#include "TextureManager.h"



GameObject::GameObject(const char* textureSheet, int x, int y)
{
	objTexture = TextureManager::LoadTexture(textureSheet);
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = 32;
	srcRect.h = 32;
	xpos = x;
	ypos = y;
	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = 32;
	destRect.h = 32;
}

GameObject::~GameObject()
{
}

void GameObject::Update()
{
	xpos++;
	ypos++;
	destRect.x = xpos;
	destRect.y = ypos;
}

void GameObject::Render()
{
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}
