#include<iostream>
#pragma once
int add(int n)
{
	int i;
	int a=1;
	for ( i = 1; i <= n; i++)
	{
		a = a * i;
		
	}
	return (a);
}