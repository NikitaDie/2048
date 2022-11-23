#include <conio.h>
#include "common.h"

enum direct { u = 72, 
	d = 80, 
	r = 77, 
	l = 75 };

int check_input() {
	_getch();
	switch (_getch())
	{
	case u:
		return UP;
	case d:
		return DOWN;
	case r:
		return RIGHT;

	case l:
		return LEFT;
	
	}
	
}