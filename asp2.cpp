#include <iostream>

using namespace std;

void row_sort(double * arr, int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if ( * (arr + i) < * (arr + j)) {
        double temp = * (arr + i);
        *(arr + i) = * (arr + j);
        *(arr + j) = temp;
      }
    }
  }
}

int main() {
    int n;
    cout« "Enter the order of the square matrix: ";
    cin» n;

    double A[n][n];

    // Input matrix A
    cout« "Enter the elements of matrix A:"«
    endl;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin» A[i][j];
      }
    }

    // Find row with max sum
    int max_row = 0;
    double max_sum = 0;
    for (int i = 0; i < n; i++) {
      double row_sum = 0;
      for (int j = 0; j < n; j++) {
        row_sum += A[i][j];
      }
      if (row_sum > max_sum) {
        max_sum = row_sum;
        max_row = i;
      }
    }

    // Sort rows of matrix A in descending order of values in max row
    double max_row_values[n];
    for (int i = 0; i < n; i++) {
      max_row_values[i] = A[max_row][i];
    }
    row_sort(max_row_values, n);

    for (int i = 0; i < n; i++) {
      double current_row_values[n];
      for (int j = 0; j < n; j++) {
        current_row_values[j] = A[i][j];
      }
      row_sort(current_row_values, n);

      for (int j = 0; j < n; j++) {
        if (current_row_values[j] == max_row_values[0]) {
          for (int k = 0; k < n; k++) {
            double temp = A[i][k];
            A[i][k] = A[max_row][k];
            A[max_row][k] = temp;
          }
          break;
        }
      }
    }

    // Output matrix A
    cout« "Matrix A sorted in descending order of values in max row:"«
    endl;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout« A[i][j]«
        " ";
      }
      cout« endl;
    }

    return 0;
