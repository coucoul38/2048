#include "Button.h"
#include <SDL.h>
#include <SDL_ttf.h>

Button::Button(SDL_Window* window, SDL_Renderer* renderer, int x, int y, int w, int h, SDL_Color* color, char* text) {
	m_pos.x = x;
	m_pos.y = y;
	m_pos.h = h;
	m_pos.w = w;
	m_renderer = renderer;
	m_window = window;
	m_color = color;


}