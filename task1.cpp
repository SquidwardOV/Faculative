#include <iostream>
#include <Windows.h>

using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian");
    int n, maxc = 0, count = 1;

    cin >> n;
    if (n == 0) {
        count = 0;
    }
    maxc = n;
    while (n != 0) {
        cin >> n;
        if (n == maxc) {
            count += 1;
        }
        if ((n > maxc) & (n!=0)) {
            maxc = n;
            count == 0;
        }
    }
    if (count != 0) {
        cout << "Максимальный элемент: " << maxc << " " << "Количество вхождений максимального элемента: " << count;
    }
    else{
        cout << "Пустая последовательность";
    }
    return 0;
}
