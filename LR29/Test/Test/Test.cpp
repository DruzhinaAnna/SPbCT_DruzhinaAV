#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    setlocale(LC_ALL, "rus");
    float a, b, c, P;
    cout << "\n a=";
    cin >> a;
    cout << "\n b=";
    cin >> b;
    cout << "\n c=";
    cin >> c;
    if (a + b > c && a + c > b && b + c > a)
    {
        P = a + b + c;
        cout << "\n Периметр равен=" << P;
    }
    else
        cout << "\n Неверные исходные данные";
}