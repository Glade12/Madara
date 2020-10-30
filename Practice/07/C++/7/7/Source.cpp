#include <iostream>
#include <cmath>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	int g;
	cout << "1.Длина сторон " << endl << "2.Координаты точек" << endl;
	cin >> g;
	double a, b, c, x1, x2, x3, y1, y2, y3, s, p;
	switch (g) {
	case 1:
		cout << "Введите длины сторон" << endl;
		cin >> a >> b >> c;
		if (a + b > c && a + c > b && c + b > a) {
			p = (a + b + c) / 2;
			s = sqrt(p * (p - a) * (p - b) * (p - c));
			cout << "S =" << s;
		}
		else {
			cout << "Треугольник с такими сторонами не существует";

		}

		break;
	case 2:
		cout << " Введите координаты точек" << endl;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		a = sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));
		b = sqrt(((x3 - x2) * (x3 - x2)) + ((y3 - y2) * (y3 - y2)));
		c = sqrt(((x3 - x1) * (x3 - x1)) + ((y3 - y1) * (y3 - y1)));
		if (a + b > c && a + c > b && c + b > a) {
			p = (a + b + c) / 2;
			s = sqrt(p * (p - a) * (p - b) * (p - c));
			cout << "S =" << s;
		}
		else {
			cout << "Треугольник с такими координатами не существует";










		}




	}
}
