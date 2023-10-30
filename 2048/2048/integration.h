#include <string>
#include "grid.h"

class IntegrationTest {
public:
	int size_x;
	int size_y;
	IntegrationTest();

	bool Test1Left();
	bool Test1Right();
	bool Test1Up();
	bool Test1Down();

	void test();

	~IntegrationTest();
};