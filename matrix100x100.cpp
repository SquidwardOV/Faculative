#include <iostream>

#include <fstream>

#include <cstdlib>

using namespace std;

int main() {
  // Создаем файл и записываем в него матрицу
  ofstream file("matrix.txt");

  if (!file) {
    cou << "Ошибка открытия файла!<<
    endl;
    return 1;
  }

  // Записываем размер матрицы
  file << "100 100<<
  endl;

  // Заполняем матрицу случайными целыми числами
  for (int i = 0; i < 100; ++i) {
    for (int j = 0; j < 100; ++j) {
      fil << rand() % 100<< " ";
    }
    file << endl;
  }

  // Закрываем файл
  file.close();

  return 0;
}
