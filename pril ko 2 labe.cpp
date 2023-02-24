#include <iostream>
#include <vector>
using namespace std;

vector<int> addPolynomials(vector<int> A, vector<int> B) {
    // определяем степень многочлена C, равную большей из степеней A и B
    int n = max(A.size(), B.size()) - 1;
    
    // создаем вектор C и заполняем его нулями
    vector<int> C(n+1, 0);
    
    // складываем коэффициенты многочленов A и B и записываем результат в многочлен C
    for (int i = 0; i <= n; i++) {
        if (i < A.size()) {
            C[i] += A[i];
        }
        if (i < B.size()) {
            C[i] += B[i];
        }
    }
    
    return C;
}

int main() {
    vector<int> A = {1, 2, 3}; // многочлен A = 1 + 2x + 3x^2
    vector<int> B = {4, 5};    // многочлен B = 4 + 5x
    
    vector<int> C = addPolynomials(A, B); // многочлен C = A + B
    
    // выводим многочлен C на экран
    for (int i = 0; i < C.size(); i++) {
        cout << C[i] << "x^" << i << " ";
        if (i < C.size()-1) {
            cout << "+ ";
        }
    }
    cout << endl;
    
    return 0;
}
