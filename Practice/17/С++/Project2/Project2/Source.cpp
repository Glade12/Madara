#include <iostream>

using namespace std;
int main()	
{
	setlocale(LC_ALL, "Russian");
	int a,b,f,c,j;
	int y[37];
	int p[37];// счетчик для выпавших чисел
	b = 0;
	f = 0;
	c = 0; // переменная позволяющая работать с счетчиком
	for (j = 0; j <= 36; j++) {
		y[j] = j ;
		p[j] = 0;
	}
	for (int i = 1; i <= 12; i++) { // старт игры
		cin >> a;
		if (a < 0) // проверка на нечетные числа
		{
			break;
		}
		switch (a) // определение цвета
		{
		case 2:
		case 4:
		case 6:
		case 8:
		case 10:
		case 11:
		case 13:
		case 15:
		case 17:
		case 20:
		case 22:
		case 24:
		case 26:
		case 28:
		case 29:
		case 31:
		case 33:
		case 35: b++;
			break;
		default: f++;
			break;
		}       //конец определения
		
		for (j = 0; j <= 36; j++) // цикл по заполнению счетчика
		{
			if (a == j)
			{
				p[j]++;

			}
			if (p[j] > c)
			{
				c = p[j];
			}
		}
		
		for (j = 0; j <= 36; j++){ // вывод часто выпадающих чисел 
		
		if (p[j] == c)
			    {
				cout << j << " ";
			    }
		}
		
		cout << endl;
		
		for (j = 0; j <= 36; j++) //вывод не выпавших
			if (a == y[j]) 
			{
				y[j]=-1;
			}
			else 
			{
				if (y[j] >= 0) 
				{
					cout << y[j] << " ";
				}
			}

			
		cout << endl;
		cout << f << " " << b; // вывод цветов
		cout << endl;

	}
	
	}