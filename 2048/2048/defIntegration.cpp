#include "integration.h"
#include "colorCodes.h"
using namespace color;

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
		{2,2,0,4},
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

	if (success) {
		std::cout << green << "Test1 passed\n" << "\033[0m";
	}
	else {
		std::cout << red << "Test1 failed" << "\033[0m";
	}

	std::cout << "Expected result:\n";
	for (int col = 0; col < 4; col++)
	{
		for (int row = 0; row < 4; row++) {
			if (expected[col][row] != 0) {
				std::cout << yellowBG << expected[col][row] << reset << " "; //blocks are displayed in red
			}
			else {
				std::cout << expected[col][row] << " ";
			}
		}
		std::cout << "\n";
	}
	std::cout << "Actual result:\n";
	grid->print();

	return success;
}

bool IntegrationTest::test() {
	bool working = true;
	working = Test1();
	if (working) {
		std::cout << "All integration tests passed successfully.\n";
	}
	return working;
}

IntegrationTest::~IntegrationTest()
{
	std::cout << "out";
}