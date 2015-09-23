#ifndef WINDOW
#define WINDOW
#include "Screen.h"
#include <vector>
class Window_mgr
{
private:
	std::vector<Screen> screens{ Screen(24, 80, ' ') };
};
#endif