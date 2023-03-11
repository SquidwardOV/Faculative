#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int N = 3; // Количество сотрудников

struct Employee {
    string lastName;
    string firstName;
    string middleName;
    string department;
    string position;
    int birthYear;
    int salary[12];
    string gender;
};

int main() {
    Employee employees[N];

    // Считываем данные о сотрудниках из файла
    ifstream in_file("employees.txt");
    if (!in_file) {
        cerr << "Cannot open input file" << endl;
        return 1;
    }
    for (int i = 0; i < N; ++i) {
        in_file >> employees[i].lastName >> employees[i].firstName >> employees[i].middleName;
        in_file >> employees[i].department >> employees[i].position >> employees[i].birthYear;
        for (int j = 0; j < 12; ++j) {
            in_file >> employees[i].salary[j];
        }
        in_file >> employees[i].gender;
    }
    in_file.close();

    // Изменяем зарплату сотрудников
    string department_name;
    cout << "Enter department name: ";
    cin >> department_name;

    for (int i = 0; i < N; ++i) {
        if (employees[i].department == department_name && 2023 - employees[i].birthYear < 60) {
            employees[i].salary[0] *= 1.15; // Увеличиваем зарплату за январь на 15%
        }
    }

    // Выводим обновленные данные о сотрудниках в файл
    ofstream out_file("updated_employees.txt");
    if (!out_file) {
        cerr << "Cannot open output file" << endl;
        return 1;
    }
    for (int i = 0; i < N; ++i) {
        out_file << employees[i].lastName << " " << employees[i].firstName << " " << employees[i].middleName << endl;
        out_file << employees[i].department << " " << employees[i].position << " " << employees[i].birthYear << endl;
        for (int j = 0; j < 12; ++j) {
            out_file << employees[i].salary[j] << " ";
        }
        out_file << employees[i].gender << endl;
    }
    out_file.close();

    return 0;
}
