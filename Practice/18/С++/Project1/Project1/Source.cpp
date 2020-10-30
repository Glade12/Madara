#include<iostream>
#include<map>
#include<cmath>
#include <string>
using namespace std;
int main() {
	string a = "halloklempnerdasistfantastischfluggegecheimen";// словарный запас
	string b;
	cin >> b;// стоп-слово
	double m = a.size();// кол-во символов в словарном запасе
	double k = b.size();// кол-во символов в стоп-слове
	map<char, int> h;
	double n = 1;
	for (int i = 0; i < m; i++)// позволяет сколько раз повторяються элементы
	{
		h[a[i]]++;
	}
	
	for (int i = 0; i < k; i++)
	{
		n = n * h[b[i]];
	}
	
	cout << n / pow(m,k);//подсчет вероятности
	
	
}