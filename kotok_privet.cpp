#include <iostream>
#include <Windows.h>

using std::cout;
using std::cin;
using std::endl;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n, m;
    cout << "Введите размерность массива:" << endl;
    cin >> n;
    cin >> m;
    int** arr = new int* [n];
    for (int i = 0; i < n; ++i) {
        arr[i] = new int[m];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i<j) {
                arr[i][j] = rand() % 3 + 1;
            }
            if (i == j) {
                arr[i][j] = 0;
            }
            if(i>j) {
                arr[i][j] = -1;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << arr[i][j] << '\t';
        }
        cout << endl;
    }
    for (int i = 0; i < n; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
}
