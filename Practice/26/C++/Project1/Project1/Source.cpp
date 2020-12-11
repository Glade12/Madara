#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <windows.h>

template<typename T>
void print(std::vector<T> a) {
	for (int i = 0; i < a.size(); i++) {
		std::cout << a[i] << ' ';
	}
	std::cout << std::endl;
}
template<typename T>
std::vector<T> BozoSort(std::vector<T>list, int c, bool k = true)
{
	bool f = 1;
	while (f) {
		f = 0;
		int r1 = rand() % c;
		int r2 = rand() % c;
		std::swap(list[r1], list[r2]);
		for (int i = 1; i < c; i++) {
			if (k) {
				if (list[i - 1] > list[i]) {
					f = 1;
					break;
				}
			}
			else {
				if (list[i - 1] < list[i]) {
					f = 1;
					break;

				}
			}

		}
	}
	return(list);
}
template<typename T>
std::vector<T> BozoSort(std::vector<std::vector<T>> list2, int p, bool k = true) {
	bool f = 1;
	while (f) {
		f = 0;
		int r1 = rand() % p;
		int r2 = rand() % p;
		int r3 = rand() % p;
		int r4 = rand() % p;
		std::swap(list2[r1][r2], list2[r3][r4]);
		for (int i = 0; i < p; i++) {
			for (int j = 1; j < p; j++) {
				if (k) {
					if (j == 1 and i > 0) {
						if (list2[i - 1][p - 1] > list2[i][j - 1]) {
							f = 1;
							i = p;
							break;
						}
						else {
							if (list2[i][j - 1] > list2[i][j]) {
								f = 1;
								i = p;
								break;
							}
						}
					}
					else {
						if (list2[i][j - 1] > list2[i][j]) {
							f = 1;
							i = p;
							break;
						}
					}
				}
				else {
					if (j == 1 and i > 0) {
						if (list2[i - 1][p - 1] < list2[i][j - 1]) {
							f = 1;
							i = p;
							break;
						}
						else {
							if (list2[i][j - 1] < list2[i][j]) {
								f = 1;
								i = p;
								break;
							}
						}
					}
					else {
						if (list2[i][j - 1] < list2[i][j]) {
							f = 1;
							i = p;
							break;
						}
					}
				}
			}
		}
	}
	std::vector<T> v2;
	for (int i = 0; i < p; i++) {
		for (int j = 0; j < p; j++) {
			v2.push_back(list2[i][j]);
		}
	}
	return(v2);
}
template<typename T>
std::vector<T> BozoSort(T first, T second, T third, bool k = true) {
	bool f = 1;
	while (f) {
		f = 0;
		int r = rand() % 3;
		if (r == 0) {
			std::swap(first, second);
		}
		if (r == 1) {
			std::swap(second, third);
		}
		if (r == 2) {
			std::swap(first, third);
		}
		if (k) {
			if (first > second) {
				f = 1;
			}
			if (second > third) {
				f = 1;
			}
		}
		else {
			if (first < second) {
				f = 1;
			}
			if (second < third) {
				f = 1;
			}
		}
	}
	std::vector<T> v3;
	v3.push_back(first);
	v3.push_back(second);
	v3.push_back(third);
	return v3;
}
template<typename T>
void User(T Val) {

	using namespace std;
	cout << "Введите число" << endl;
	int c;
	cin >> c;
	cout << "Введите числа" << endl;
	vector <T> list;
	vector<T> help;
	vector<vector<T>> list2;
	list.reserve(0);
	T a;
	int u = 0;
	int p = sqrt(c);
	for (int i = 0; i < c; i++)
	{
		cin >> a;
		list.push_back(a);
		help.push_back(a);
		if (sqrt(c) - u == 1)
		{
			list2.push_back(help);
			help.clear();
			u = 0;
		}
		else { u++; }
	}
	cout << endl;
	T first = list[0];
	T second = list[1];
	T third = list[2];
	cout << "Вектор" << endl;
	print<<(BozoSort(list, c));
	ptint<<(BozoSort(list, c, false));
	cout << "Вектор в векторе" << endl;
	print(BozoSort(list2, p));
	print(BozoSort(list2, p, false));
	cout << "Числа" << endl;
	print<<(BozoSort(first, second, third));
	print<<(BozoSort(first, second, third, false));
}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	std::cout << "double type" << std::endl;
	User((double)2.0);
	std::cout << std::endl << "string type" << std::endl;
	User((std::string)"2");
}