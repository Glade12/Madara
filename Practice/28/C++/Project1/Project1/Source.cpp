#include <iostream>
#include <vector>
#include<map>
#include <string>

void print_factorization(unsigned int n) {
	std::vector <std::string> one;
	std::map <std::string, int> a;
	int sol = 2;
	while (n > 1) {
		while (n % sol == 0) {
			std::string o = std::to_string(sol);
			one.push_back(o);
			n = n / sol;
		}
		sol++;
	}
	bool f = 1;
	int s = one.size();
	if (s > 1) {
		while(f) {
			int i = 1;
			while (1) {
				if (s - i == 0) {
					f = 0;
					break;
				}
				else {
					if (one[i] == one[i - 1]) {
						a[one[i]]++;
						one.erase(one.begin() + (i - 1));
						s = one.size();
						break;
					}
					i++;
				}
			}
			}
		for (int i = 0; i < one.size(); i++) {
			if (a.find(one[i])!=a.cend()) {
				one[i] = (one[i]) + "^" + std::to_string(a[one[i]] + 1);
			}
		}
		std::string b = one[0];
		if (one.size() > 1) {
			for (int i = 1; i < one.size(); i++) {
				b = b + "*" + one[i];
			}
			std::cout << b;
		}
		else{ std::cout << b; }
	
	}
	else {
		std::string b = one[0];
		std::cout << b;
	}
	
}


int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	std::cout << "¬ведите" << std::endl;
	std::cin >> n;
	print_factorization(n);
}