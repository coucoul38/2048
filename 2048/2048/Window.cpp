#include <iostream>
#include "Window.h"
#include <SDL.h>

Window::Window(int width, int height){
	// Initialize SDL
	SDL_Init(SDL_INIT_EVERYTHING);
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::cout << "Error, couldn't initizialize SDL, error : " << SDL_GetError() << "\n";
	}
	else {
		std::cout << "Successfully initialized SDL\n";
	}

	/* Creates a SDL window */
	window = SDL_CreateWindow("SDL Example", /* Title of the SDL window */
		SDL_WINDOWPOS_UNDEFINED, /* Position x of the window */
		SDL_WINDOWPOS_UNDEFINED, /* Position y of the window */
		width, /* Width of the window in pixels */
		height, /* Height of the window in pixels */
		0); /* Additional flag(s) */
	if (window == NULL) {
		std::cout << "Error while creating window: " << SDL_GetError();
		exit(1);
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL) {
		std::cout << "Error while creating renderer: " << SDL_GetError();
		exit(1);
	}

	SDL_RaiseWindow(window);
	SDL_SetWindowTitle(window, "2048");

}

SDL_Window* Window::GetWindow() {
	return window;
}
SDL_Renderer* Window::GetRenderer() {
	return renderer;
}

int Window::ChangeColor(SDL_Color color) {
	SDL_Renderer* renderer = SDL_GetRenderer(window);
	if (SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a) != 0) {
		fprintf(stderr, "Erreur SetRenderDrawColor : %s", SDL_GetError());
		return -1;
	}
	if (SDL_RenderClear(renderer) != 0) {
		fprintf(stderr, "Erreur RenderClear : %s", SDL_GetError());
		return -1;
	}
	return 0;
}

Window::~Window(){
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}