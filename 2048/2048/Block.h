#pragma once
#include <SDL_rect.h>
struct SDL_Window;
struct SDL_Texture;
struct SDL_Renderer;
#include <SDL_ttf.h>
//struct TTF_Font;

class Block
{
public:	
	SDL_Window* m_window;
	SDL_Texture* m_texture;
	SDL_Renderer* m_renderer;
	SDL_Rect m_pos;
	TTF_Font* font;

	Block(SDL_Window* window, SDL_Texture* texture, SDL_Renderer* renderer, int x, int y, int size_grid);

	int Reset();

	int Draw(int value);

	void ChangeImg(SDL_Texture* texture);

	void Move(int x, int y);
	~Block();
};