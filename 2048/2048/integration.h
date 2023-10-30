#include <vector>
#include <iostream>
#include <string>

class IntegrationTest {
public:

	void Test1() 
	{
		int start[4][4] = 
		{ 
			{2,2,2,2},
			{0,0,0,0},
			{0,0,0,0},
			{0,0,0,0}
		};

		int expected[4][4] =
		{
			{4,4,0,0},
			{0,0,0,0},
			{0,0,0,0},
			{0,0,0,0}
		};

		Grid grid(start);

		grid.slideLeft(true);

		bool success = grid.Compare(expected);

	}

	void print() {
		system("cls");
		for (int col = 0; col < size_x; col++)
		{
			for (int row = 0; row < size_y; row++) {
				std::cout << grid[col][row] << " ";
			}
			std::cout << "\n";
		}
	}

	bool slide(std::string direction) {
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
		std::cout << "\nWin: " << win << "\n";
		return win;
	}

	bool slideLeft(bool merge) {
		bool win = false;
		for (int i = 0; i < 2; i++)
		{
			for (int col = 0; col < size_x; col++)
			{
				for (int row = size_y - 1; row >= 0; row--) {
					if (grids[i][col][row] != 0 && grid[col][row - 1] == 0) {
						grids[i][col][row - 1] = grid[col][row];

						if (mergeGrid[col][row] == true) {
							mergeGrid[col][row - 1] = true;
							mergeGrid[col][row] = false;
						}
						grid[col][row] = 0;
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
		}
		return win;
	}

	bool slideRight(bool merge) {
		bool win = false;
		for (int col = 0; col < size_x; col++)
		{	
			for (int row = 0; row < size_y - 1; row++) {
				if (grid[col][row] != 0 && grid[col][row + 1] == 0) {
					grid[col][row + 1] = grid[col][row];

					if (mergeGrid[col][row] == true) {
						mergeGrid[col][row + 1] = true;
						mergeGrid[col][row] = false;
					}
					grid[col][row] = 0;
					slideRight(false);
				}
				else if (grid[col][row + 1] == grid[col][row] && mergeGrid[col][row] == false && merge) { //if two blocks are the same, combine them
					grid[col][row + 1] += grid[col][row]; 
					mergeGrid[col][row + 1] = true;
					grid[col][row] = 0;
					slideRight(false);

					if (grid[col][row + 1] == 2048) { win = true; } //win detection
				}
			}
		}
		return win;
	}

	bool slideDown(bool merge) {
		bool win = false;
		for (int col = 0; col < size_x - 1; col++)
		{
			for (int row = 0; row < size_y; row++) {
				if (grid[col][row] != 0 && grid[col + 1][row] == 0) {
					grid[col + 1][row] = grid[col][row];
					grid[col][row] = 0;

					if (mergeGrid[col][row] == true) {
						mergeGrid[col+1][row] = true;
						mergeGrid[col][row] = false;
					}
					slideDown(false);
				}
				else if (grid[col+1][row] == grid[col][row] && mergeGrid[col][row] == false && merge) { //if two blocks are the same, combine them
					grid[col+1][row] += grid[col][row];
					if (grid[col + 1][row] == 2048) {
						win = true;
					}
					mergeGrid[col+1][row] = true;
					grid[col][row] = 0;
					slideDown(false);
				}
			}
		}
		return win;
	}

	bool slideUp(bool merge) {
		bool win = false;
		for (int col = size_x-1; col >=1; col--)
		{
			for (int row = 0; row < size_y; row++) {
				//std::cout << "\n Col: " << col << " Row: " << row;
				if (grid[col][row] != 0 && grid[col - 1][row] == 0) {
					grid[col - 1][row] = grid[col][row];
					grid[col][row] = 0;

					if (mergeGrid[col][row] == true) {
						mergeGrid[col-1][row] = true;
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

	bool addBlock() {
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
			return true;
		}
		else {
			//pick a random available spot in the list and add a block here
			int spot = rand() % availableList.size();
			grid[availableList[spot][0]][availableList[spot][1]] = 2;
		}
	}

	bool test() {
		bool working = true;
		return working;
	}

	~IntGrid()
	{
		std::cout << "out";
		for (int i = 0; i < size_x; i++)
		{
			free(mergeGrid[i]);
		}
		free(grids);
		free(mergeGrid);
	}
};

