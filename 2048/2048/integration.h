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
	
	bool Test2Left();
	bool Test2Right();
	bool Test2Up();
	bool Test2Down();

	bool Test3Left();
	bool Test3Right();
	bool Test3Up();
	bool Test3Down();

	void test();

	~IntegrationTest();
};