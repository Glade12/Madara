#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "�������� �������!" << endl;
	int n = 1;
	int x,v,u;
	v = 1 + rand() % 100;
	while (1) 
	{
	 cin >> x;
	 if (n==5)
	 {
		if (x==v)
		{
			cout << "���������� �� �������!" << endl << "������ ������ ������?(1-��)" << endl;
			cin >> u;
			if (u==1)
			{
				n = 1;
				v = 1 + rand() % 100;
				cin >> x;

			}
			else
			{
				break;
			}
		}
		else
		{
			cout << "�� ���������. ���� ��������:" << v << endl << "������ ������ ������?(1-��)" << endl;
			cin >> u;
			if (u == 1)
			{
				n = 1;
				v = 1 + rand() % 100;
				cin >> x;
			}
			else
			{
				break;
			}
		
		
		}
	 
	 
	 
	 }
	 if (x==v)
	 {
		 cout << "���������� �� �������!" << endl << "������ ������ ������?(1-��)" << endl;
		 cin >> u;
		 if (u == 1)
		 {
			 n = 1;
			 v = 1 + rand() % 100;
			 cin >> x;
		 }
		 else
		 {
			 break;
		 }
	 
	 }
	 if (x > v) 
	 {
		 cout << "���������� ����� ������" << endl;
	 }
	 else
	 {
		 cout << "���������� ����� ������" << endl;
	 }
	 n++;
	}

}