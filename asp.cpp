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

double row_min(double * arr, int n) {
  double min = * arr;
  for (int i = 1; i < n; i++) {
    if ( * (arr + i) < min) {
      min = * (arr + i);
    }
  }
  return min;
}

double row_product(double * arr, int n) {
  double product = 1;
  for (int i = 0; i < n; i++) {
    product *= * (arr + i);
  }
  return product;
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
    for (int j = 0; j < n; j++) {
      B[i][j] = A[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    double current_row_values[n];
    for (int j = 0; j < n; j++) {
      current_row_values[j] = A[i][j];
    }
    row_sort(current_row_values, n);

    for (int j = 0; j < n; j++) {
      if (current_row_values[j] == max_row_values[0]) {
        for (int k = 0; k < n; k++) {
          B[i][k] = A[max_row][k];
        }
        break;
      }
    }
  }

  // Output matrix B
  cout« "Matrix B:"«
  endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout« B[i][j]«
      " ";
    }
    cout« endl;
  }

  // Find min element and product of values in max row
  double min_element = row_min(max_row_values, n);
  double product = row_product(max_row_values, n);

  cout« "Min element in max row: "«
  min_element« endl;
  cout« "Product of values in max row: "«
  product« endl;

  return 0;
}
