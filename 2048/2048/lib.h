#include <vector>
#include <iostream>
#include <string>

const std::string red("\033[0;31m");
const std::string reset("\033[0m");

class Grid {
public:
	int size_x;
	int size_y;
	int** grid = (int**)malloc(sizeof(int*)*size_x);
	bool** mergeGrid = (bool**)malloc(sizeof(bool*) * size_x); //this grid is used to know if a block resulted from a merge with another block, to prevent "cascade merge" in the same move
	//std::vector<int> grid = {};

	Grid(int x, int y) 
	{	
		srand(time(NULL)); //Initialize random seed
		size_x = x;
		size_y = y;
		int starterBlock1[] = {rand() % 4 , rand() % 4};
		int starterBlock2[] = { rand() % 4 , rand() % 4 };

		//create the grid
		for (int i = 0; i < size_x; i++)
		{
			int* col = (int*) malloc(sizeof(int)*size_y);
			bool* mergeCol = (bool*)malloc(sizeof(bool) * size_y);
			for (int z = 0; z < size_y; z++)
			{	
				if (i == starterBlock1[0] && z == starterBlock1[1]) {
					col[z] = 2;
				} else if (i == starterBlock2[0] && z == starterBlock2[1]) {
					col[z] = 2;
				}
				else
				{
					col[z] = 0;
				}
				mergeCol[z] = false;
			}
			grid[i] = col;
			mergeGrid[i] = mergeCol;
		}
	}

	void print() {
		for (int col = 0; col < size_x; col++)
		{
			for (int row = 0; row < size_y; row++) {
				if (grid[col][row] != 0) {
					std::cout << red << grid[col][row] << reset << " "; //blocks are displayed in red
				}
				else {
					std::cout << grid[col][row] << " ";
				}
			}
			std::cout << "\n";
		}
	}

	void slide(std::string direction) {
		//reset mergeGrid
		for (int i = 0; i < size_x; i++)
		{
			for (int z = 0; z < size_y; z++)
			{
				mergeGrid[i][z] = false;
			}
		}


		if (direction == "up") {
			
		}
		else if (direction == "down") {

		}
		else if (direction == "left") {
			slideLeft();
		}
		else if (direction == "right") {
			slideRight();
		}
	}

	void slideLeft() {
		for (int col = 0; col < size_x; col++)
		{
			for (int row = size_y - 1; row >= 0; row--) {
				if (grid[col][row] != 0 && grid[col][row - 1] == 0) {
					grid[col][row - 1] = grid[col][row];
					grid[col][row] = 0;
					slideLeft();
				}
				else if (grid[col][row - 1] == grid[col][row] && mergeGrid[col][row]==false) { //if two blocks are the same, combine them
					grid[col][row - 1] += grid[col][row];
					mergeGrid[col][row - 1] = true;
					grid[col][row] = 0;
					//slideLeft();
				}
			}
		}
	}

	void slideRight() {
		for (int col = 0; col < size_x; col++)
		{
			for (int row = 0; row < size_y - 1; row++) {
				if (grid[col][row] != 0 && grid[col][row + 1] == 0) {
					grid[col][row + 1] = grid[col][row];
					grid[col][row] = 0;
					slideRight();
					//std::cout << "Moving [" << col << "," << row << "] to [" << col << "," << row + 1 << "]\n";
				}
				else if (grid[col][row + 1] == grid[col][row] && mergeGrid[col][row] == false) { //if two blocks are the same, combine them
					grid[col][row + 1] += grid[col][row];
					mergeGrid[col][row + 1] = true;
					grid[col][row] = 0;
					//slideLeft();
				}
			}
		}
	}

	int addBlock() {
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
					availableList.push_back({i,z}); //save the spot in the list
				}
			}
		}
		if (available == 0) {
			std::cout << "YOU LOOSE\n";
			return 0;
		}
		else {
			//pick a random available spot in the list and add a block here
			int spot = rand() % availableList.size();
			grid[availableList[spot][0]][availableList[spot][1]] = 2;
		}
	}

	~Grid()
	{
		std::cout << "out";
	}
};

