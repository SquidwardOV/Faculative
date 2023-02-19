//Напишите функцию сложения двух многочленов. Представьте
//каждый многочлен в виде массива коэффициентов, где A^i– коэффициентперед x^i


#include <iostream> 
using namespace std; 

// Функция для сложения двух многочленов 
int* addPolynomial(int A[], int B[], int m, int n) 
{ 
    int *sum = new int[max(m, n)]; 
    
    // Добавляем соответствующие коэффициенты 
    for (int i = 0; i<m; i++) 
        sum[i] = A[i]; 
    
    // Добавляем соответствующие коэффициенты 
    for (int i = 0; i<n; i++) 
        sum[i] += B[i]; 
    
    return sum; 
} 

// Функция для вывода многочлена 
void printPolynomial(int poly[], int n) 
{ 
    for (int i = 0; i<n; i++) 
    { 
        cout << poly[i]; 
        if (i != 0) 
            cout << "x^" << i ; 
        if (i != n-1) 
        cout << " + "; 
    } 
} 

// Главная функция 
int main() 
{ 
    int A[] = {5, 0, 10, 6}; 
    int B[] = {1, 2, 4}; 
    int m = sizeof(A)/sizeof(A[0]); 
    int n = sizeof(B)/sizeof(B[0]); 
    
    cout << "First polynomial is n"; 
    printPolynomial(A, m); 
    cout << endl; 
    cout << "Second polynomial is n"; 
    printPolynomial(B, n); 
    cout << endl; 
    int *sum = addPolynomial(A, B, m, n); 
    int size = max(m, n); 
    
    cout << "Sum polynomial is n"; 
    printPolynomial(sum, size); 
    return 0; 
}
