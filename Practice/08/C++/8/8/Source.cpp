#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	double a, b;
	char c;
	cout << "������� ������ �����, ����, ������ �����" << endl;
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
			cout << "�� �������� �� ";
		
		}
		else {
			cout << a / b;
		}
		
		break;





	}
      

	}









