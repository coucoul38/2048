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
}

SDL_Window* Window::GetWindow() {
	return window;
}

Window::~Window(){

	/* Frees memory */
	SDL_DestroyWindow(window);

	/* Shuts down all SDL subsystems */
	SDL_Quit();
}