#include <iostream>
#include "Block.h"
#include <SDL.h>

Block::Block(SDL_Window* window, SDL_Texture* texture, SDL_Renderer* renderer) {
}

int Block::Blit() {
	SDL_Surface* winSurface = SDL_GetWindowSurface(window);
	SDL_Rect dest;
	dest.x = 100;
	dest.y = 100;
	SDL_UpdateWindowSurface(window);
	
	return false;
}

Block::~Block() {
	SDL_DestroyTexture(texture);
}