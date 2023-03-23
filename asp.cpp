#include <iostream>

using namespace std;

double row_min(double * arr, int n) {
  double min = * arr;
  for (int i = 1; i < n; i++) {
    if ( * (arr + i) < min) {
      min = * (arr + i);
    }
  }
  return min;
}

double col_max(double ** arr, int n, int col) {
  double max = arr[0][col];
  for (int i = 1; i < n; i++) {
    if (arr[i][col] > max) {
      max = arr[i][col];
    }
  }
  return max;
}

double ** matrix_multiply(double ** A, double ** B, int n) {
  double ** C = new double * [n];
  for (int i = 0; i < n; i++) {
    C[i] = new double[n];
    for (int j = 0; j < n; j++) {
      C[i][j] = 0;
      for (int k = 0; k < n; k++) {
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }
  return C;
}

int main() {
  int n;
  cout« "Enter the order of the square matrix: ";
  cin» n;

  double A[n][n];
  double B[n][n];

  // Input matrix A
  cout« "Enter the elements of matrix A:"«
  endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin» A[i][j];
    }
  }

  // Input matrix B
  cout« "Enter the elements of matrix B:"«
  endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin» B[i][j];
    }
  }

  // Create array of row minima for matrix A
  double A_row_minima[n];
  for (int i = 0; i < n; i++) {
    double row_values[n];
    for (int j = 0; j < n; j++) {
      row_values[j] = A[i][j];
    }
    A_row_minima[i] = row_min(row_values, n);
  }

  // Create array of column maxima for matrix B
  double B_col_maxima[n];
  for (int i = 0; i < n; i++) {
    B_col_maxima[i] = col_max(B, n, i);
  }

  // Multiply row minima of A by column maxima of B
  double C[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      C[i][j] = A_row_minima[i] * B_col_maxima[j];
    }
  }

  // Output matrix C
  cout« "Matrix C:"«
  endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout« C[i][j]«
      " ";
    }
    cout« endl;
  }

  return 0;
}
