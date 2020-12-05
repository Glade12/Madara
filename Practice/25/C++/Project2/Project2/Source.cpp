#include <iostream>
#include <vector>
#include <cmath>
#include <string>

void print(std::vector<int> a){
	for (int i = 0; i < a.size(); i++) {
		std::cout << a[i] << ' ';
	}
	std::cout << std::endl;
}

std::vector<int> BozoSort(std::vector<int>list, int c, bool k = true)
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

std::vector<int> BozoSort(std::vector<std::vector<int>> list2, int p, bool k = true) {
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
					if (j==1 and i>0) {
						if (list2[i-1][p-1] > list2[i][j-1]) {
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
	std::vector<int> v2;
	for (int i = 0; i < p; i++) {
		for(int j =0; j<p;j++){
			v2.push_back(list2[i][j]);
		}
	}
	return(v2);
}

std::vector<int> BozoSort(int first, int second, int third, bool k = true) {
	bool f = 1;
	while (f) {
		f = 0;
		int r = rand() % 3;
		if (r == 0){
			std::swap(first, second);
		}
		if (r == 1) {
			std::swap(second, third);
		}
		if (r == 2) {
			std::swap(first, third);
		}
		if (k){
			if (first > second) {
				f = 1;
			}
			if (second > third) {
				f = 1;
			}
		}
		else{
			if (first < second) {
				f = 1;
			}
			if (second < third) {
				f = 1;
			}
		}
	}
	std::vector<int> v3;
	v3.push_back(first);
	v3.push_back(second);
	v3.push_back(third);
	return v3;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	using namespace std;
	cout << "¬ведите предел" << endl;
	int c;
	cin >> c;
	cout << "¬ведите числа" << endl;
	vector <int> list;
	vector<int> help;
	vector<vector<int>> list2;
	list.reserve(0);
	int a;
	int u = 0;
	int p = sqrt(c);
	for(int i=0; i<c; i++)
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
	int first = list[0];
	int second = list[1];
	int third = list[2];
	print(BozoSort(list, c));
	print(BozoSort(list, c, false));
	print(BozoSort(list2, p));
	print(BozoSort(list2, p, false));
	print(BozoSort(first, second, third));
	print(BozoSort(first, second, third, false));
}