#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	double a, b, c, D,x1,x2;
	cout << "Введите коэффиценты" << endl;
	cin >> a;
	cin >> b;
	cin >> c;
	D = b * b - 4 * a * c;
	if (D < 0) {
		cout << "Нет корней";
	}
	else {
		if (D ==0) {
			cout << "Корни совпадают и равны: " << b / (2 * a);
		}
		else cout << "Первый корень равен: " << (b + D) / (2 * a) << endl << "Второй корень равен: " << (b -D) / (2 * a);




	}























}