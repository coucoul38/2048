#pragma once
#include <string>
#include <SDL.h>
#include <SDL_ttf.h>

class Button
{
public:
	SDL_Window* m_window;
	SDL_Texture* m_texture;
	SDL_Renderer* m_renderer;
	SDL_Rect m_pos;
	TTF_Font* font;
	SDL_Color* m_color;

	Button(SDL_Window* window, SDL_Renderer* renderer, int x,int y, int w, int h, SDL_Color* color, char* text);

	int Draw();

	~Button();
};

