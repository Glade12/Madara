#include <iostream>
#include <vector>
#include <algorithm>

bool comp2(int a, int b) { return (a > b); }

 
std::vector <int> main_cicle(std::vector <int> signals, int n) {
	std::vector <int> support;
	for (int i = 0; i < n; i++) {
		if (i < 5){
			support.push_back(signals[i]);
			
		}
		else {
			if (support[0] > signals[i]) {
				std::swap(support[0], signals[i]);
			}
		}
		std::sort(support.begin(), support.end(), comp2);
		
	}
	
	return(support);
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	std::cout << "¬ведите кол-во сигналов" << std::endl;
	std::cin >> n;
	std::cout << std::endl;
	std::vector<int> signals;
	std::cout << "¬ведите сигналы" << std::endl;
	for (int i = 0; i < n; i++) {
		int y;
		std::cin >> y;
		signals.push_back(y);

	}

	std::cout << std::endl;
	for (int i = 0; i < 5; i++) {
		std::cout << main_cicle(signals, n)[i]<<" ";
	}
}