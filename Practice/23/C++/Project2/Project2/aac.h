#ifndef acc_h
#define acc_h
#include <iostream>
#include <cmath>
#include "add.h"

double aac(int k)
{
	double x = 0;
	double sinx = 0;
	double i = 1;
	const double PI = 3.14;
	for ( i=1;i<=k;i++)
	{
		sinx = sinx + (pow(x, (2 * i + 1)) / (2 * i + 1));
		x = x + (PI / 180);
	}
	return sinx;// ак бы не пыталс€ не могу вернуть значени€ типа double
}



#endif
