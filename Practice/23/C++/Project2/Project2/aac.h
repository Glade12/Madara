#ifndef acc_h
#define acc_h
#include <iostream>
#include <cmath>
#include "add.h"

double aac(double x)
{
	float c = 0;
	for (int n = 0; n <= 4; n++) {
		c = c + pow(-1, n) * pow(x, 2 * n + 1) / add(2 * n + 1);
	}
	return c;
}


#endif
