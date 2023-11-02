#include "Grid.h"
#include <vector>
#include <iostream>
#include <string>
#include "colorCodes.h"
#include "Block.h"

Grid::Grid(int input[4][4]) {
	size_x = 4;
	size_y = 4;
	mergeGrid = (bool**)malloc(sizeof(bool*) * 4); //this grid is used to know if a block resulted from a merge with another block, to prevent "cascade merge" in the same move
	grid = (int**)malloc(sizeof(int*) * 4);
	//visGrid = (Block**)malloc(sizeof(Block*) * size_x)
	for (int i = 0; i < 4; i++)
	{
		bool* mergeCol = (bool*)malloc(sizeof(bool) * size_y);
		//Block* visCol = (Block*)malloc(sizeof(Block) * size_y);
		for (int j = 0; j < 4; j++)
		{
			mergeCol[j] = false;
			//visCol[j] = new Block();
		}
		grid[i]= input[i];
		mergeGrid[i] = mergeCol;
	}
}

Grid::Grid(int x, int y, SDL_Window* window, SDL_Texture* IMGblockEmpty, SDL_Renderer* renderer) {
	{
		srand(time(NULL)); //Initialize random seed
		size_x = x;
		size_y = y;
		int size_grid = size_x + size_y;

		grid = (int**)malloc(sizeof(int*) * size_x);
		mergeGrid = (bool**)malloc(sizeof(bool*) * size_x); //this grid is used to know if a block resulted from a merge with another block, to prevent "cascade merge" in the same move
		visualGrid = (Block***)malloc(sizeof(Block**) * size_x);

		int starterBlock1[] = { rand() % 4 , rand() % 4 };
		int starterBlock2[] = { rand() % 4 , rand() % 4 };

		//create the grid
		for (int i = 0; i < size_x; i++)
		{
			int* col = (int*)malloc(sizeof(int) * size_y);
			bool* mergeCol = (bool*)malloc(sizeof(bool) * size_y);
			Block** visualCol = (Block**)malloc(sizeof(Block) * size_y);
			for (int z = 0; z < size_y; z++)
			{
				if (i == starterBlock1[0] && z == starterBlock1[1]) {
					col[z] = 2;
				}
				else if (i == starterBlock2[0] && z == starterBlock2[1]) {
					col[z] = 2;
				}
				else
				{
					col[z] = 0;
				}
				visualCol[z] = new Block(window, IMGblockEmpty, renderer, i * size_grid* 12, z * size_grid * 12, size_grid );
				mergeCol[z] = false;
			}
			grid[i] = col;
			mergeGrid[i] = mergeCol;
			visualGrid[i] = visualCol;
		}
	}
}

void Grid::print() {
	{
		//system("cls");
		if (visualGrid) {
			visualGrid[0][0]->Reset();
		}
		for (int col = 0; col < size_x; col++)
		{
			for (int row = 0; row < size_y; row++) {
				if (grid[col][row] != 0) {
					std::cout << color::yellowBG << grid[col][row] << color::reset << " "; //blocks are displayed in red
				}
				else {
					std::cout << grid[col][row] << " ";
				}
				if (visualGrid) {
					visualGrid[row][col]->Draw(grid[col][row]);
				}
			}
			std::cout << "\n";
		}
	}
}

bool Grid::slide(std::string direction){
	bool win = false;
	//reset mergeGrid
	for (int i = 0; i < size_x; i++)
	{
		for (int z = 0; z < size_y; z++)
		{
			mergeGrid[i][z] = false;
		}
	}

	if (direction == "up") {
		win = slideUp(true);
	}
	else if (direction == "down") {
		win = slideDown(true);
	}
	else if (direction == "left") {
		win = slideLeft(true);
	}
	else if (direction == "right") {
		win = slideRight(true);
	}
	//std::cout << "\nWin: " << win << "\n";
	return win;
}

bool Grid::slideLeft(bool merge) {
	bool win = false;
	for (int col = 0; col < size_y; col++)
	{
		for (int row = size_x - 1; row >= 1; row--) {
			//std::cout << "\n Col: " << col << " Row: " << row;
			if (grid[col][row] != 0 && grid[col][row - 1] == 0) {
				grid[col][row - 1] = grid[col][row];
				grid[col][row] = 0;

				if (mergeGrid[col][row] == true) {
					mergeGrid[col][row - 1] = true;
					mergeGrid[col][row] = false;
				}
				slideLeft(false);
			}
			else if (grid[col][row - 1] == grid[col][row] && mergeGrid[col][row] == false && merge) { //if two blocks are the same, combine them
				grid[col][row - 1] += grid[col][row];
				mergeGrid[col][row - 1] = true;
				grid[col][row] = 0;
				slideLeft(false);

				if (grid[col][row - 1] == 2048) { win = true; } //win detection
			}
		}
	}
	return win;
}
bool Grid::slideRight(bool merge) {
	bool win = false;
	for (int col = 0; col < size_x; col++)
	{
		for (int row = size_y - 1; row > 0; row--) {
			if (grid[col][row] == 0 && grid[col][row - 1] > 0) {
				grid[col][row] = grid[col][row - 1];
				grid[col][row - 1] = 0;

				if (mergeGrid[col][row - 1] == true) {
					mergeGrid[col][row] = true;
					mergeGrid[col][row - 1] = false;
				}
				
				slideRight(false);
			}
			else if (grid[col][row - 1] == grid[col][row] && mergeGrid[col][row] == false && mergeGrid[col][row - 1] == false) { //if two blocks are the same, combine them
				grid[col][row] += grid[col][row - 1];
				mergeGrid[col][row] = true;
				grid[col][row - 1] = 0;
				slideRight(false);

				if (grid[col][row] == 2048) { win = true; } //win detection
			}
		}
	}
	return win;
}
bool Grid::slideDown(bool merge) {
	bool win = false;
	for (int col = 0; col < size_x - 1; col++)
	{
		for (int row = 0; row < size_y; row++) {
			if (grid[col][row] != 0 && grid[col + 1][row] == 0) {
				grid[col + 1][row] = grid[col][row];
				grid[col][row] = 0;

				if (mergeGrid[col][row] == true) {
					mergeGrid[col + 1][row] = true;
					mergeGrid[col][row] = false;
				}
				slideDown(false);
			}
			else if (grid[col + 1][row] == grid[col][row] && mergeGrid[col][row] == false && merge) { //if two blocks are the same, combine them
				grid[col + 1][row] += grid[col][row];
				if (grid[col + 1][row] == 2048) {
					win = true;
				}
				mergeGrid[col + 1][row] = true;
				grid[col][row] = 0;
				slideDown(false);
			}
		}
	}
	return win;
}
bool Grid::slideUp(bool merge){
	bool win = false;
	for (int col = size_x - 1; col >= 1; col--)
	{
		for (int row = 0; row < size_y; row++) {
			//std::cout << "\n Col: " << col << " Row: " << row;
			if (grid[col][row] != 0 && grid[col - 1][row] == 0) {
				grid[col - 1][row] = grid[col][row];
				grid[col][row] = 0;

				if (mergeGrid[col][row] == true) {
					mergeGrid[col - 1][row] = true;
					mergeGrid[col][row] = false;
				}
				slideUp(false);
			}
			else if (grid[col - 1][row] == grid[col][row] && mergeGrid[col][row] == false && merge) { //if two blocks are the same, combine them
				grid[col - 1][row] += grid[col][row];
				mergeGrid[col - 1][row] = true;
				grid[col][row] = 0;
				slideUp(false);

				if (grid[col - 1][row] == 2048) { win = true; } //win detection
			}
		}
	}
	return win;
}

bool Grid::addBlock() {
	int x = rand() % 4;
	int y = rand() % 4;
	int available = 0;
	std::vector<std::vector<int>> availableList;

	//check for available spots
	for (int i = 0; i < size_x; i++)
	{
		for (int z = 0; z < size_y; z++)
		{
			if (grid[i][z] == 0) {
				available++;
				availableList.push_back({ i,z }); //save the spot in the list
			}
		}
	}
	if (available == 0) {
		std::cout << "YOU LOOSE\n";
		return true;
	}
	else {
		//pick a random available spot in the list and add a block here
		int spot = rand() % availableList.size();
		grid[availableList[spot][0]][availableList[spot][1]] = 2;
	}
}

//For integration tests
bool Grid::compare(int compGrid[4][4]) {
	bool same = true;
	for (int col = 0; col < 4; col++)
	{
		for (int row = 0; row < 4; row++)
		{
			if (grid[col][row] != compGrid[col][row]) {
				same = false;
			}
		}
	}
	return same;
}

Grid::~Grid() {
	std::cout << "out";
	for (int i = 0; i < size_x; i++)
	{
		free(grid[i]);
		free(mergeGrid[i]);
	}
	free(grid);
	free(mergeGrid);
}