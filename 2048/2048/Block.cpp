#include <iostream>
#include "Block.h"
#include <SDL.h>

Block::Block(SDL_Window* window, SDL_Texture* texture, SDL_Renderer* renderer) {
	m_pos.x = 10;
	m_pos.y = 10;
	m_renderer = renderer;
	m_texture = texture;
	m_window = window;
	SDL_QueryTexture(m_texture, NULL, NULL, &m_pos.w, &m_pos.h);
}

int Block::Draw() {
	//clear canvas
	//SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	//SDL_RenderClear(renderer);
	SDL_RenderCopy(m_renderer, m_texture, NULL, &m_pos);
	SDL_RenderPresent(m_renderer);

	return false;
}

void Block::Move(int x, int y) {
	m_pos.x = x;
	m_pos.y = y;
}

Block::~Block() {
	SDL_DestroyTexture(m_texture);
}