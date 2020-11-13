#ifndef aad_h
#define aad_h
#include "add.h"
#include <iostream>
int aad(int k,int n)
{
	int i;
	double C;
	for (i=1;i<=k;i++)
	{
		C = (add(n) /( add(i) * add((n - k))));
	}
	return C;
}

#endif
