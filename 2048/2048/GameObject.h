#pragma once
struct SDL_Window;
struct SDL_Surface;

class GameObject
{
public:	
	GameObject(SDL_Window* window, SDL_Surface* image);
	int Blit();
	~GameObject();
};