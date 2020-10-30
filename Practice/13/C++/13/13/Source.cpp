#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	cout << "Введите число" << endl;
	int n, b;
	b = 1;
	cin >> n;
	cout << endl;
	for (int i = 1; i <= n; i++) {
		if (i == n) {
			b = i;
		}
			else {
				if
					((i!=1)&&(n % i == 0)) {
					cout << "Состовное число" << endl;
					i = n + 1;
					b = i;
				}
			}

		}


	
	if (b - n == 0) {
		cout << "Простое число";

	}
}