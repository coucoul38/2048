#include <vector>
#include <iostream>
#include <string>
#include "grid.h"

class IntegrationTest {
public:
	int size_x = 4;
	int size_y = 4;

	IntegrationTest(int test) {
		if (test == 1) {
			Test1();
		}
	}

	bool Test1() 
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



		//Grid grid(start);
		Grid* grid = new Grid(start);

		grid->slideLeft(true);

		bool success = grid->Compare(expected);
		return success;
	}

	bool test() {
		bool working = true;
		return working;
	}

	~IntegrationTest()
	{
		std::cout << "out";
		
	}
};

