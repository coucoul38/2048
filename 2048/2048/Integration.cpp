#include <iostream>
#include "Integration.h"
#include "colorCodes.h"
using namespace color;

IntegrationTest::IntegrationTest() {
	this->test();
	size_x = 4;
	size_y = 4;
}

bool IntegrationTest::Test1Left() {
	int start[4][4] =
	{
		{2,2,0,4},
		{2,2,0,4},
		{2,2,0,4},
		{2,2,0,4}
	};

	int expected[4][4] =
	{
		{4,4,0,0},
		{4,4,0,0},
		{4,4,0,0},
		{4,4,0,0}
	};

	//Grid grid(start);
	Grid* grid = new Grid(start);

	grid->slide("left");

	bool success = grid->compare(expected);

	if (success) {
		std::cout << green << "Test1Left passed\n" << "\033[0m";
	}
	else {
		std::cout << red << "Test1Left failed\n" << "\033[0m";
		std::cout << "---------------\nExpected result:\n";
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
		std::cout << "\nActual result:\n";
		grid->print();
		std::cout << "---------------\n";
	}

	return success;
}

bool IntegrationTest::Test1Right() {
	int start[4][4] =
	{
		{2,2,0,4},
		{2,2,0,4},
		{2,2,0,4},
		{2,2,0,4}
	};

	int expected[4][4] =
	{
		{0,0,4,4},
		{0,0,4,4},
		{0,0,4,4},
		{0,0,4,4}
	};

	//Grid grid(start);
	Grid* grid = new Grid(start);

	grid->slide("right");

	bool success = grid->compare(expected);

	if (success) {
		std::cout << green << "Test1Right passed\n" << "\033[0m";
	}
	else {
		std::cout << red << "Test1Right failed\n" << "\033[0m";
		std::cout << "---------------\nExpected result:\n";
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
		std::cout << "\nActual result:\n";
		grid->print();
		std::cout << "---------------\n";
	}

	return success;
}

bool IntegrationTest::Test1Up() {
	int start[4][4] =
	{
		{2,2,2,2},
		{2,2,2,2},
		{0,0,0,0},
		{4,4,4,4}
	};

	int expected[4][4] =
	{
		{4,4,4,4},
		{4,4,4,4},
		{0,0,0,0},
		{0,0,0,0}
	};

	//Grid grid(start);
	Grid* grid = new Grid(start);

	grid->slide("up");

	bool success = grid->compare(expected);

	if (success) {
		std::cout << green << "Test1Up passed\n" << "\033[0m";
	}
	else {
		std::cout << red << "Test1Up failed\n" << "\033[0m";
		std::cout << "---------------\nExpected result:\n";
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
		std::cout << "\nActual result:\n";
		grid->print();
		std::cout << "---------------\n";
	}

	return success;
}

bool IntegrationTest::Test1Down() {
	int start[4][4] =
	{
		{2,2,2,2},
		{2,2,2,2},
		{0,0,0,0},
		{4,4,4,4}
	};

	int expected[4][4] =
	{
		{0,0,0,0},
		{0,0,0,0},
		{4,4,4,4},
		{4,4,4,4}
	};

	//Grid grid(start);
	Grid* grid = new Grid(start);

	grid->slide("down");

	bool success = grid->compare(expected);

	if (success) {
		std::cout << green << "Test1Down passed\n" << "\033[0m";
	}
	else {
		std::cout << red << "Test1Down failed\n" << "\033[0m";
		std::cout << "---------------\nExpected result:\n";
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
		std::cout << "\nActual result:\n";
		grid->print();
		std::cout << "---------------\n";
	}

	return success;
}

void IntegrationTest::test() {
	Test1Left();
	Test1Right();
	Test1Up();
	Test1Down();
}

IntegrationTest::~IntegrationTest()
{
	std::cout << "out";
}