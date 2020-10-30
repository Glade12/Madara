#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "¬ведите число" << endl;
	int x, n, a;
	cin >> n;
	x = 0;
	a = 1;
	while (1)
		if ((x <= n) && (a <= n))
		{
			x++;
			a = a * 2;
		}
		else 
		{
			break;
		}
	cout << x;

}