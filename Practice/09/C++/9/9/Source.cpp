#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	int a, b,f,g;
	char c,h;
	cout << "Введите время первого и второго" << endl;
	cin >> a >> c >> b >> f >> h >> g;
	if ((b - g <= 15) || (g - b <= 15)) {
		if ((a - f < 0) || (f - a < 0)) {
			cout << "Встреча состоиться";




	}
		else {
			cout << "Встреча не состоиться";




		}

	
	}
	else {
		cout << "Встреча не состоиться";




	}



}
