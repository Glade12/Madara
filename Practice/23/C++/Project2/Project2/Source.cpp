#include <iostream>
#include "add.h"
#include "aac.h"
#include "aad.h"

using namespace std;

int main() 
{
	const double PI = 3.14;
	cout << "n" << "	" << "n!" << endl;
	int i;
	for(i=1; i<=10; i++)
	{
		cout << i << "	" << add(i) << endl;
	}
	cout << "x" << "	" << "sinx" << "	" << endl;
	double b;
	for(b=0;b<=(PI/4);b+=(PI/180))
	{
		cout << b << "	" << aac(b) << endl;//Не получается вернуть значение типа double
	}
	int a;
	cout << "k" << "	" << "C(k,10)" << "		" << endl;
	for (a = 1; a <= 10; a++)
		cout << a << "	" << aad(a,10) << "		" << endl;
}
