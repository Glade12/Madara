#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	double x0, v0, t;
	cout << "������� ��������� ����������, ��������� �������� � ����� �������������� " << endl;
	cin >> x0 >> v0 >> t;
	cout << "x(t)= " << (x0 + v0 * t - (9.8 * t * t) / 2);





}