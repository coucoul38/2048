#include <vector>
#include <iostream>

class Grid {
public:
	int size_x;
	int size_y;
	int** grid = (int**)malloc(sizeof(int*)*size_x);
	//std::vector<int> grid = {};

	Grid(int x, int y) 
	{	
		size_x = x;
		size_y = y;
		for (size_t i = 0; i < size_x; i++)
		{
			int* col = (int*) malloc(sizeof(int)*size_y);
			//std::vector<int> col = {};
			for (size_t z = 0; z < size_y; z++)
			{
				col[z] = 0;
			}
			grid[i] = col;
		}
	}

	void print() {
		for (size_t col = 0; col < size_x; col++)
		{
			for (size_t row = 0; row < size_y; row++) {
				std::cout << grid[col][row] << " ";
			}
			std::cout << "\n";
		}
	}

	~Grid() 
	{
		free(grid);
	}
};

