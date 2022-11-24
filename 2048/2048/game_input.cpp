#include <conio.h>
#include "common.h"

enum direct { u = 72, 
	d = 80, 
	r = 77, 
	l = 75 };

int check_input() {
	while (true) {
		int gt = _getch();
		if (gt == 27) return 27;
		else if (gt == 114) return 114;

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

		
	};
	
}

int check_y() {
	while (true)
	{
		switch (_getch())
		{
		case 89:
			return true;
		case 121:
			return true;
		case 78:
			return false;
		case 110:
			return false;
		}
	}

}