#pragma once
struct SDL_Window;
struct SDL_Surface;
struct SDL_Rect;

class Block
{
public:	
	SDL_Texture* texture;
	SDL_Window* window;
	//SDL_Rect dest;
	Block(SDL_Window* window, SDL_Texture* texture, SDL_Renderer* renderer);
	int Blit();
	~Block();
};