#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	double a, b, c, D,x1,x2;
	cout << "������� �����������" << endl;
	cin >> a;
	cin >> b;
	cin >> c;
	D = b * b - 4 * a * c;
	if (D < 0) {
		cout << "��� ������";
	}
	else {
		if (D ==0) {
			cout << "����� ��������� � �����: " << b / (2 * a);
		}
		else cout << "������ ������ �����: " << (b + D) / (2 * a) << endl << "������ ������ �����: " << (b -D) / (2 * a);




	}























}