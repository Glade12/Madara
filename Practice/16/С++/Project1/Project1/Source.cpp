#include<locale>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    int l, n, p;
    p = 0;
    cout << "¬ведите кол-во билетов" << endl;
    cin >> n;
    cout << "¬ведите билеты"<< endl;
    string m{};
    for (l = 1; l <= n; l++)
    {
        cin >> m;
        if (m[0] == 'a' && m[4] == '5' && m[5] == '5' && m[6] == '6' && m[7] == '6' && m[8] == '1')
        {
            cout << m << ' ';
 
        }
        else
        {
            p = p + 1;
        }
    }
    if (p == n)
    {
        cout << "-1";
    }
    return 0;
}
