#pragma once
struct SDL_Window;

class Window
{
public:
	SDL_Window* window;

	Window(int width, int height);
	
	SDL_Window* GetWindow();

	~Window();
};