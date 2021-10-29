#include <vector>
#include <iostream>
#include<ctime>
#include<iomanip>
using namespace std;

int main() {
    setlocale(LC_ALL, "RUSSIAN");
    int n, vec[20][20];

    cout << "Введите число n:" << endl;
    cin >> n;

    cout << "Исходная матрица:" << endl;
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {
            vec[i][j] = rand() % 10;
            cout << vec[i][j] << "  ";

        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = n - i; j < n; j++)
        {
            vec[i][j] = 0;
        }
    }
    cout << endl;
    cout << "Получившаяся матрица" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << vec[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl;
    system("pause");
}
