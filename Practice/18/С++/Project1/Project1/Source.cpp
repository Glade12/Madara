#include<iostream>
#include<map>
#include<cmath>
#include <string>
using namespace std;
int main() {
	string a = "halloklempnerdasistfantastischfluggegecheimen";// ��������� �����
	string b;
	cin >> b;// ����-�����
	double m = a.size();// ���-�� �������� � ��������� ������
	double k = b.size();// ���-�� �������� � ����-�����
	map<char, int> h;
	double n = 1;
	for (int i = 0; i < m; i++)// ��������� ������� ��� ������������ ��������
	{
		h[a[i]]++;
	}
	
	for (int i = 0; i < k; i++)
	{
		n = n * h[b[i]];
	}
	
	cout << n / pow(m,k);//������� �����������
	
	
}