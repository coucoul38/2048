#include <iostream>
#include "Integration.h"
#include "colorCodes.h"

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

	int startCopy[4][4] =
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
		std::cout << color::green << "Test1Left passed\n" << "\033[0m";
	}
	else {
		std::cout << color::red << "Test1Left failed\n" << "\033[0m";
		std::cout << "---------------\nStarting Grid:\n";
		for (int col = 0; col < 4; col++)
		{
			for (int row = 0; row < 4; row++) {
				if (startCopy[col][row] != 0) {
					std::cout << color::yellowBG << startCopy[col][row] << color::reset << " "; //blocks are displayed in red
				}
				else {
					std::cout << startCopy[col][row] << " ";
				}
			}
			std::cout << "\n";
		}
		std::cout << "---------------\nExpected result:\n";
		for (int col = 0; col < 4; col++)
		{
			for (int row = 0; row < 4; row++) {
				if (expected[col][row] != 0) {
					std::cout << color::yellowBG << expected[col][row] << color::reset << " "; //blocks are displayed in red
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
		std::cout << color::green << "Test1Right passed\n" << "\033[0m";
	}
	else {
		std::cout << color::red << "Test1Right failed\n" << "\033[0m";
		std::cout << "---------------\nExpected result:\n";
		for (int col = 0; col < 4; col++)
		{
			for (int row = 0; row < 4; row++) {
				if (expected[col][row] != 0) {
					std::cout << color::yellowBG << expected[col][row] << color::reset << " "; //blocks are displayed in red
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
		std::cout << color::green << "Test1Up passed\n" << "\033[0m";
	}
	else {
		std::cout << color::red << "Test1Up failed\n" << "\033[0m";
		std::cout << "---------------\nExpected result:\n";
		for (int col = 0; col < 4; col++)
		{
			for (int row = 0; row < 4; row++) {
				if (expected[col][row] != 0) {
					std::cout << color::yellowBG << expected[col][row] << color::reset << " "; //blocks are displayed in red
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
		std::cout << color::green << "Test1Down passed\n" << "\033[0m";
	}
	else {
		std::cout << color::red << "Test1Down failed\n" << "\033[0m";
		std::cout << "---------------\nExpected result:\n";
		for (int col = 0; col < 4; col++)
		{
			for (int row = 0; row < 4; row++) {
				if (expected[col][row] != 0) {
					std::cout << color::yellowBG << expected[col][row] << color::reset << " "; //blocks are displayed in red
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

bool IntegrationTest::Test2Left() {
	int start[4][4] =
	{
		{0,2,2,2},
		{0,2,2,2},
		{0,2,2,2},
		{0,2,2,2}
	};

	int startCopy[4][4] =
	{
		{0,2,2,2},
		{0,2,2,2},
		{0,2,2,2},
		{0,2,2,2}
	};

	int expected[4][4] =
	{
		{4,2,0,0},
		{4,2,0,0},
		{4,2,0,0},
		{4,2,0,0}
	};

	//Grid grid(start);
	Grid* grid = new Grid(start);

	grid->slide("left");

	bool success = grid->compare(expected);

	if (success) {
		std::cout << color::green << "Test2Left passed\n" << "\033[0m";
	}
	else {
		std::cout << color::red << "Test2Left failed\n" << "\033[0m";
		std::cout << "---------------\nStarting Grid:\n";
		for (int col = 0; col < 4; col++)
		{
			for (int row = 0; row < 4; row++) {
				if (startCopy[col][row] != 0) {
					std::cout << color::yellowBG << startCopy[col][row] << color::reset << " "; //blocks are displayed in red
				}
				else {
					std::cout << startCopy[col][row] << " ";
				}
			}
			std::cout << "\n";
		}
		std::cout << "---------------\nExpected result:\n";
		for (int col = 0; col < 4; col++)
		{
			for (int row = 0; row < 4; row++) {
				if (expected[col][row] != 0) {
					std::cout << color::yellowBG << expected[col][row] << color::reset << " "; //blocks are displayed in red
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
bool IntegrationTest::Test2Right() {
	int start[4][4] =
	{
		{2,2,2,0},
		{2,2,2,0},
		{2,2,2,0},
		{2,2,2,0}
	};

	int startCopy[4][4] =
	{
		{2,2,2,0},
		{2,2,2,0},
		{2,2,2,0},
		{2,2,2,0}
	};

	int expected[4][4] =
	{
		{0,0,2,4},
		{0,0,2,4},
		{0,0,2,4},
		{0,0,2,4}
	};

	//Grid grid(start);
	Grid* grid = new Grid(start);

	grid->slide("right");

	bool success = grid->compare(expected);

	if (success) {
		std::cout << color::green << "Test2Right passed\n" << "\033[0m";
	}
	else {
		std::cout << color::red << "Test2Right failed\n" << "\033[0m";
		std::cout << "---------------\nStarting Grid:\n";
		for (int col = 0; col < 4; col++)
		{
			for (int row = 0; row < 4; row++) {
				if (startCopy[col][row] != 0) {
					std::cout << color::yellowBG << startCopy[col][row] << color::reset << " "; //blocks are displayed in red
				}
				else {
					std::cout << startCopy[col][row] << " ";
				}
			}
			std::cout << "\n";
		}
		std::cout << "---------------\nExpected result:\n";
		for (int col = 0; col < 4; col++)
		{
			for (int row = 0; row < 4; row++) {
				if (expected[col][row] != 0) {
					std::cout << color::yellowBG << expected[col][row] << color::reset << " "; //blocks are displayed in red
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
bool IntegrationTest::Test2Up() {
	int start[4][4] =
	{
		{2,2,2,2},
		{2,2,2,2},
		{0,0,0,0},
		{2,2,2,2}
	};

	int startCopy[4][4] =
	{
		{2,2,2,2},
		{2,2,2,2},
		{0,0,0,0},
		{2,2,2,2}
	};

	int expected[4][4] =
	{
		{4,4,4,4},
		{2,2,2,2},
		{0,0,0,0},
		{0,0,0,0}
	};

	//Grid grid(start);
	Grid* grid = new Grid(start);

	grid->slide("up");

	bool success = grid->compare(expected);

	if (success) {
		std::cout << color::green << "Test2Up passed\n" << "\033[0m";
	}
	else {
		std::cout << color::red << "Test2Up failed\n" << "\033[0m";
		std::cout << "---------------\nStarting Grid:\n";
		for (int col = 0; col < 4; col++)
		{
			for (int row = 0; row < 4; row++) {
				if (startCopy[col][row] != 0) {
					std::cout << color::yellowBG << startCopy[col][row] << color::reset << " "; //blocks are displayed in red
				}
				else {
					std::cout << startCopy[col][row] << " ";
				}
			}
			std::cout << "\n";
		}
		std::cout << "---------------\nExpected result:\n";
		for (int col = 0; col < 4; col++)
		{
			for (int row = 0; row < 4; row++) {
				if (expected[col][row] != 0) {
					std::cout << color::yellowBG << expected[col][row] << color::reset << " "; //blocks are displayed in red
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
bool IntegrationTest::Test2Down() {
	int start[4][4] =
	{
		{2,2,2,2},
		{2,2,2,2},
		{0,0,0,0},
		{2,2,2,2}
	};

	int startCopy[4][4] =
	{
		{2,2,2,2},
		{2,2,2,2},
		{0,0,0,0},
		{2,2,2,2}
	};

	int expected[4][4] =
	{
		{0,0,0,0},
		{0,0,0,0},
		{2,2,2,2},
		{4,4,4,4},
	};

	//Grid grid(start);
	Grid* grid = new Grid(start);

	grid->slide("down");

	bool success = grid->compare(expected);

	if (success) {
		std::cout << color::green << "Test2Down passed\n" << "\033[0m";
	}
	else {
		std::cout << color::red << "Test2Down failed\n" << "\033[0m";
		std::cout << "---------------\nStarting Grid:\n";
		for (int col = 0; col < 4; col++)
		{
			for (int row = 0; row < 4; row++) {
				if (startCopy[col][row] != 0) {
					std::cout << color::yellowBG << startCopy[col][row] << color::reset << " "; //blocks are displayed in red
				}
				else {
					std::cout << startCopy[col][row] << " ";
				}
			}
			std::cout << "\n";
		}
		std::cout << "---------------\nExpected result:\n";
		for (int col = 0; col < 4; col++)
		{
			for (int row = 0; row < 4; row++) {
				if (expected[col][row] != 0) {
					std::cout << color::yellowBG << expected[col][row] << color::reset << " "; //blocks are displayed in red
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

bool IntegrationTest::Test3Left() {
	int start[4][4] =
	{
		{2,0,0,2},
		{2,0,0,2},
		{2,0,0,2},
		{2,0,0,2}
	};

	int startCopy[4][4] =
	{
		{2,0,0,2},
		{2,0,0,2},
		{2,0,0,2},
		{2,0,0,2}
	};

	int expected[4][4] =
	{
		{4,0,0,0},
		{4,0,0,0},
		{4,0,0,0},
		{4,0,0,0}
	};

	//Grid grid(start);
	Grid* grid = new Grid(start);

	grid->slide("left");

	bool success = grid->compare(expected);

	if (success) {
		std::cout << color::green << "Test3Left passed\n" << "\033[0m";
	}
	else {
		std::cout << color::red << "Test3Left failed\n" << "\033[0m";
		std::cout << "---------------\nStarting Grid:\n";
		for (int col = 0; col < 4; col++)
		{
			for (int row = 0; row < 4; row++) {
				if (startCopy[col][row] != 0) {
					std::cout << color::yellowBG << startCopy[col][row] << color::reset << " "; //blocks are displayed in red
				}
				else {
					std::cout << startCopy[col][row] << " ";
				}
			}
			std::cout << "\n";
		}
		std::cout << "---------------\nExpected result:\n";
		for (int col = 0; col < 4; col++)
		{
			for (int row = 0; row < 4; row++) {
				if (expected[col][row] != 0) {
					std::cout << color::yellowBG << expected[col][row] << color::reset << " "; //blocks are displayed in red
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
bool IntegrationTest::Test3Right() {
	int start[4][4] =
	{
		{2,0,0,2},
		{2,0,0,2},
		{2,0,0,2},
		{2,0,0,2}
	};

	int startCopy[4][4] =
	{
		{2,0,0,2},
		{2,0,0,2},
		{2,0,0,2},
		{2,0,0,2}
	};

	int expected[4][4] =
	{
		{0,0,0,4},
		{0,0,0,4},
		{0,0,0,4},
		{0,0,0,4}
	};

	//Grid grid(start);
	Grid* grid = new Grid(start);

	grid->slide("right");

	bool success = grid->compare(expected);

	if (success) {
		std::cout << color::green << "Test3Right passed\n" << "\033[0m";
	}
	else {
		std::cout << color::red << "Test3Right failed\n" << "\033[0m";
		std::cout << "---------------\nStarting Grid:\n";
		for (int col = 0; col < 4; col++)
		{
			for (int row = 0; row < 4; row++) {
				if (startCopy[col][row] != 0) {
					std::cout << color::yellowBG << startCopy[col][row] << color::reset << " "; //blocks are displayed in red
				}
				else {
					std::cout << startCopy[col][row] << " ";
				}
			}
			std::cout << "\n";
		}
		std::cout << "---------------\nExpected result:\n";
		for (int col = 0; col < 4; col++)
		{
			for (int row = 0; row < 4; row++) {
				if (expected[col][row] != 0) {
					std::cout << color::yellowBG << expected[col][row] << color::reset << " "; //blocks are displayed in red
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
bool IntegrationTest::Test3Up() {
	int start[4][4] =
	{
		{2,2,2,2},
		{0,0,0,0},
		{0,0,0,0},
		{2,2,2,2}
	};

	int startCopy[4][4] =
	{
		{2,2,2,2},
		{0,0,0,0},
		{0,0,0,0},
		{2,2,2,2}
	};

	int expected[4][4] =
	{
		{4,4,4,4},
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0}
	};

	//Grid grid(start);
	Grid* grid = new Grid(start);

	grid->slide("up");

	bool success = grid->compare(expected);

	if (success) {
		std::cout << color::green << "Test3Up passed\n" << "\033[0m";
	}
	else {
		std::cout << color::red << "Test3Up failed\n" << "\033[0m";
		std::cout << "---------------\nStarting Grid:\n";
		for (int col = 0; col < 4; col++)
		{
			for (int row = 0; row < 4; row++) {
				if (startCopy[col][row] != 0) {
					std::cout << color::yellowBG << startCopy[col][row] << color::reset << " "; //blocks are displayed in red
				}
				else {
					std::cout << startCopy[col][row] << " ";
				}
			}
			std::cout << "\n";
		}
		std::cout << "---------------\nExpected result:\n";
		for (int col = 0; col < 4; col++)
		{
			for (int row = 0; row < 4; row++) {
				if (expected[col][row] != 0) {
					std::cout << color::yellowBG << expected[col][row] << color::reset << " "; //blocks are displayed in red
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
bool IntegrationTest::Test3Down() {
	int start[4][4] =
	{
		{2,2,2,2},
		{0,0,0,0},
		{0,0,0,0},
		{2,2,2,2}
	};

	int startCopy[4][4] =
	{
		{2,2,2,2},
		{0,0,0,0},
		{0,0,0,0},
		{2,2,2,2}
	};

	int expected[4][4] =
	{
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
		{4,4,4,4},
	};

	//Grid grid(start);
	Grid* grid = new Grid(start);

	grid->slide("down");

	bool success = grid->compare(expected);

	if (success) {
		std::cout << color::green << "Test3Down passed\n" << "\033[0m";
	}
	else {
		std::cout << color::red << "Test3Down failed\n" << "\033[0m";
		std::cout << "---------------\nStarting Grid:\n";
		for (int col = 0; col < 4; col++)
		{
			for (int row = 0; row < 4; row++) {
				if (startCopy[col][row] != 0) {
					std::cout << color::yellowBG << startCopy[col][row] << color::reset << " "; //blocks are displayed in red
				}
				else {
					std::cout << startCopy[col][row] << " ";
				}
			}
			std::cout << "\n";
		}
		std::cout << "---------------\nExpected result:\n";
		for (int col = 0; col < 4; col++)
		{
			for (int row = 0; row < 4; row++) {
				if (expected[col][row] != 0) {
					std::cout << color::yellowBG << expected[col][row] << color::reset << " "; //blocks are displayed in red
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

	Test2Left();
	Test2Right();
	Test2Up();
	Test2Down();

	Test3Left();
	Test3Right();
	Test3Up();
	Test3Down();
}

IntegrationTest::~IntegrationTest()
{
	std::cout << "out";
}