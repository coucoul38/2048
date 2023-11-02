#include <iostream>
#include "Block.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>

Block::Block(SDL_Window* window, SDL_Texture* texture, SDL_Renderer* renderer, int x, int y, int size_grid) {
	m_pos.x = x;
	m_pos.y = y;

	m_renderer = renderer;
	m_texture = texture;
	m_window = window;
	int window_h;
	int window_w;
	SDL_QueryTexture(m_texture, NULL, NULL, &m_pos.w, &m_pos.h);
	SDL_GetWindowSize(window, &window_w, &window_h);

	m_pos.h = std::min(window_w, window_h) / size_grid;
	m_pos.w = std::min(window_w, window_h) / size_grid;

	if (TTF_Init() == -1) {
		fprintf(stderr, "TTF_Init error : %s\n", TTF_GetError());
		exit(EXIT_FAILURE);
	}
	font = TTF_OpenFont("../Assets/Fonts/Poppins.ttf", 24);
	if (font == 0) {
		std::cout << "Error while importing font\n";
	}
}

int Block::Draw(int value) {
	std::string textValue = std::to_string(value);
	const char* cstr = textValue.c_str();
	SDL_Color color = { 0,0,0 };

	switch (value)
	{
	case 0:
		SDL_SetRenderDrawColor(m_renderer, 200, 200, 200, 255);
		color = { 66, 66, 62 };
		break;
	case 2:
		SDL_SetRenderDrawColor(m_renderer, 255, 248, 227, 255);
		color = { 66, 66, 62 };
		break;
	case 4:
		SDL_SetRenderDrawColor(m_renderer, 255, 227, 186, 255);
		color = { 66, 66, 62 };
		break;
	case 8:
		SDL_SetRenderDrawColor(m_renderer, 242, 177, 121, 255);
		color = { 255,255,255 };
		break;
	case 16:
		SDL_SetRenderDrawColor(m_renderer, 245, 149, 99, 255);
		color = { 255,255,255 };
		break;
	case 32:
		SDL_SetRenderDrawColor(m_renderer, 246, 124, 95, 255);
		color = { 255,255,255 };
		break;
	case 64:
		SDL_SetRenderDrawColor(m_renderer, 246, 94, 59, 255);
		color = { 255,255,255 };
		break;
	case 128:
		SDL_SetRenderDrawColor(m_renderer, 237, 207, 114, 255);
		color = { 255,255,255 };
		break;
	case 256:
		SDL_SetRenderDrawColor(m_renderer, 252, 229, 73, 255);
		color = { 255,255,255 };
		break;
	case 512:
		SDL_SetRenderDrawColor(m_renderer, 252, 229, 73, 255);
		color = { 255,255,255 };
		break;
	case 1024:
		SDL_SetRenderDrawColor(m_renderer, 252, 229, 73, 255);
		color = { 255,255,255 };
		break;

	default:
		SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
		color = { 0,0,0 };
		break;
	}
	if(value>2048){
		SDL_SetRenderDrawColor(m_renderer, 51, 51, 47, 255);
		color = { 255,255,255 };
	}

	SDL_RenderFillRect(m_renderer, &m_pos);

	//Generate number
	if (value != 0) {
		SDL_Surface* surfaceMessage = TTF_RenderText_Blended(font, cstr, color);
		SDL_Texture* Message = SDL_CreateTextureFromSurface(m_renderer, surfaceMessage);
		SDL_RenderCopy(m_renderer, Message, NULL, &m_pos);
		SDL_FreeSurface(surfaceMessage);
		SDL_DestroyTexture(Message);
	}
	SDL_RenderPresent(m_renderer);
	return 0;
}

void Block::ChangeImg(SDL_Texture* texture) {
	m_texture = texture;
}

void Block::Move(int x, int y) {
	m_pos.x = x;
	m_pos.y = y;
}

Block::~Block() {
	SDL_DestroyTexture(m_texture);
	TTF_CloseFont(font);
	TTF_Quit();
}