#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	cout << "������� ��������" << endl;
	int a, b, c;
	cin >> a >> b;
	c = a;
	a = b;
	b = c;
	cout << a << " " << b << endl;
	cout << "������� ��������" << endl;
	int f, g;
	cin >> f>> g;
	f = f - g;
	g = f + g;
	f = g - f;
	cout << f << " " << g << endl;













}