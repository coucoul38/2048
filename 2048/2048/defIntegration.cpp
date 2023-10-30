#include "integration.h"

IntegrationTest::IntegrationTest(int test) {
	if (test == 1) {
		Test1();
	}
	size_x = 4;
	size_y = 4;
}

bool IntegrationTest::Test1() {
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

	grid->slide("left");

	bool success = grid->compare(expected);
	return success;
}

bool IntegrationTest::test() {
	bool working = true;
	return working;
}

IntegrationTest::~IntegrationTest()
{
	std::cout << "out";
}