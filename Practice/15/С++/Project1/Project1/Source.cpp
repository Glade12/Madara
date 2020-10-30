#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Попробую угадать!" << endl;
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
			cout << "Поздравляю вы угадали!" << endl << "Хотите начать сначал?(1-Да)" << endl;
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
			cout << "Вы проиграли. Было загадано:" << v << endl << "Хотите начать сначал?(1-Да)" << endl;
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
		 cout << "Поздравляю вы угадали!" << endl << "Хотите начать сначал?(1-Да)" << endl;
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
		 cout << "Загаданное число меньше" << endl;
	 }
	 else
	 {
		 cout << "Загаданное число больше" << endl;
	 }
	 n++;
	}

}