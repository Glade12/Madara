#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	cout << "¬ведите число и степень, которое желаете возвести" << "\n";
	int a, b,c;
	cin >> a >> b;
	c = a;
	for (int i = 1; i < b; i++) {
		c = c * a;
	
	}
	cout << c;



	}






