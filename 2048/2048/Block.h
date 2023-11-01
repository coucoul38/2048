#pragma once
#include <SDL_rect.h>
struct SDL_Window;
struct SDL_Texture;
struct SDL_Renderer;

class Block
{
public:	
	SDL_Window* m_window;
	SDL_Texture* m_texture;
	SDL_Renderer* m_renderer;
	SDL_Rect m_pos;

	Block(SDL_Window* window, SDL_Texture* texture, SDL_Renderer* renderer);
	int Draw();
	void Move(int x, int y);
	~Block();
};