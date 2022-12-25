#include <iostream>
#include <time.h>
#include <Windows.h>
using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(0));
    int a[4][5], * p;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 5; ++j) {
            a[i][j] = rand() % 10;
        }
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 5; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n\n\n\n\n\n";
    for (int i = 0; i < 4; ++i) {
        p = a[i];
        for (int j = 0; j < 5; j++) {
            *(p + j) = 5 * i + j + 1;
            cout << a[i][j] << "\t";
        }
        cout << "\n";
    }
    getchar();
    return 0;
}
