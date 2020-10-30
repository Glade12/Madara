#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	int n,f;
	cout << "¬ведите число" << endl;
	cin >> n;
	f = 1;
	for (int i = 1; i <= n; i++) {
		f = f * i;
	}
	cout << f;


}