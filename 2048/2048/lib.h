

class Grid {
public:
	int size_x;
	int size_y;
	int** grid;

	Grid() 
	{
		for (size_t i = 0; i < size_x; i++)
		{
			int* col = {};
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
				std::cout << char(grid[col][row]);
			}
			std::cout << "\n";
		}
	}
};

