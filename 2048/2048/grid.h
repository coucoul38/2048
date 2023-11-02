#include <string>
#pragma once
struct Block;
struct SDL_Window;
struct SDL_Texture;
struct SDL_Renderer;

class Grid {
public:
	int size_x;
	int size_y;
	int** grid;
	//Block** visGrid;
	bool** mergeGrid; //this grid is used to know if a block resulted from a merge with another block, to prevent "cascade merge" in the same move
	Block*** visualGrid;

	Grid(int input[4][4]);

	Grid(int x, int y, SDL_Window* window, SDL_Texture* IMGblockEmpty, SDL_Renderer* renderer);
	
	//Methods
	void print();

	bool slide(std::string direction);

	bool slideLeft(bool merge);

	bool slideRight(bool merge);

	bool slideDown(bool merge);

	bool slideUp(bool merge);

	bool addBlock();

	//For integration tests
	bool compare(int compGrid[4][4]);

	~Grid();
};