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
		srand(time(NULL)); //Initialize random seed
		size_x = x;
		size_y = y;
		int starterBlock1[] = {rand() % 4 , rand() % 4};
		int starterBlock2[] = { rand() % 4 , rand() % 4 };
		for (size_t i = 0; i < size_x; i++)
		{
			int* col = (int*) malloc(sizeof(int)*size_y);
			//std::vector<int> col = {};
			for (size_t z = 0; z < size_y; z++)
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

	int addBlock() {
		int x = rand() % 4;
		int y = rand() % 4;
		int available = 0;
		std::vector<int> availableList;

		//check for available spots
		for (int i = 0; i < size_x; i++)
		{
			for (int z = 0; z < size_y; z++)
			{
				if (grid[i][z] == 0) {
					available++;
					availableList.insert(availableList.end(),{ i,z });
				}
			}
		}
		if (available == 0) {
			return 0;
		}
		else {
			std::cout << "\nNumber of available spots to place a new block: " << available <<"\n";
			std::cout << "availableList:\n";
			for (int i = 0; i < availableList.size()-1; i+=2) {
				std::cout << "[" << availableList[i] << ","<< availableList[i+1]<<"], ";
			}
			std::cout << "\n";
		}
	}

	~Grid()
	{
		std::cout << "out";
	}
};

