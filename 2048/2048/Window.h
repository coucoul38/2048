#pragma once
struct SDL_Window;
struct SDL_Renderer;
struct SDL_Color;

class Window
{
public:
	SDL_Window* window;
	SDL_Renderer* renderer;

	Window(int width, int height);
	
	SDL_Window* GetWindow();
	SDL_Renderer* GetRenderer();

	int ChangeColor(SDL_Color color);

	~Window();
};