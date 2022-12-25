#include <iostream>
using namespace std;
int main()
{
    const int n = 10;
    int i, j, k, c;
    int a[n];
    int * x;
    x = a;
    cout << "Введите элементы исходного массива"<< endl;
    for (i = 0; i < n; i++)
        cin >> *(x++);
    cout << "Введите k"<<endl;
    cin >> k;
    
    x = a;
    if (k > 1){
        for (i = 0; i < k; i++){
            c = *(x + n - 1);
            for (j = n - 1; j<=1 ; j--)
                *(x++) = *(x--);
            *x = c;
        }
        cout << "Полученный массив: "<< endl;
        x = a;
        for (i = 0; i<n; i++)
            cout << *(x++) << ' ';
    }
    system ("pause");
    return 0;
}
