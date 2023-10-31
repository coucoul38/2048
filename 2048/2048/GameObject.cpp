#include "GameObject.h"
#include <SDL.h>

SDL_Surface* image;
SDL_Window* window;

GameObject::GameObject(SDL_Window* win, SDL_Surface* img) {
	image = img;
	window = win;
}

int GameObject::Blit() {
	SDL_Surface* winSurface = SDL_GetWindowSurface(window);

	SDL_Rect dest;
	dest.x = 100;
	dest.y = 100;

	SDL_BlitSurface(image, NULL, winSurface, &dest);
	SDL_UpdateWindowSurface(window);
	
	return false;
}

GameObject::~GameObject() {
	SDL_FreeSurface(image);
}