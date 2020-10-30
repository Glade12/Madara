#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	double a, b;
	char c;
	cout << "Введите первое число, знак, второе число" << endl;
	cin >> a >> c >> b;
	switch (c) {
	case'+':
		cout << a + b;
		break;
	case '-':
		cout << a - b;
		break;
	case '*':
			cout << a * b;
			break;
	case '/':
		if (b == 0) {
			cout << "Не делиться на ";
		
		}
		else {
			cout << a / b;
		}
		
		break;





	}
      

	}









