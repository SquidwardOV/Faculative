#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

const int N = 10; // Количество сотрудников
const int PENSION_AGE = 65; // Возраст выхода на пенсию
const double JANUARY_INCREASE = 0.15; // Увеличение зарплаты за январь месяц

struct Employee {
    string surname;
    string name;
    string patronymic;
    string department;
    string position;
    int birthYear;
    double salary[12];
    char gender;
};

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    Employee employees[N];

    // Заполнение массива сотрудников
    // В этом примере данные считываются из файла "employees.docx"
    ifstream inputFile;
    inputFile.open("employees.docx");

    for (int i = 0; i < N; i++) {
        inputFile >> employees[i].surname >> employees[i].name >> employees[i].patronymic
            >> employees[i].department >> employees[i].position >> employees[i].birthYear
            >> employees[i].salary[0] >> employees[i].salary[1] >> employees[i].salary[2]
            >> employees[i].salary[3] >> employees[i].salary[4] >> employees[i].salary[5]
            >> employees[i].salary[6] >> employees[i].salary[7] >> employees[i].salary[8]
            >> employees[i].salary[9] >> employees[i].salary[10] >> employees[i].salary[11]
            >> employees[i].gender;
    }
    inputFile.close();

    // Находим отдел, зарплату за январь которого нужно увеличить
    string targetDepartment;
    cout << "Введите название отдела: ";
    cin >> targetDepartment;

    int targetDepartmentIndex = -1; // Индекс отдела
    for (int i = 0; i < N; i++) {
        if (employees[i].department == targetDepartment) {
            targetDepartmentIndex = i;
            break;
        }
    }

    if (targetDepartmentIndex == -1) {
        cout << "Отдел не найден" << endl;
        return 1;
    }

    // Увеличиваем зарплату за январь месяц
    for (int i = 0; i < N; i++) {
        if (i != targetDepartmentIndex) {
            continue;
        }

        int age = 2023 - employees[i].birthYear; // Вычисляем возраст
        if (age < PENSION_AGE) {
            for (int j = 0; j < 12; j++) {
                employees[i].salary[j] *= (1 + JANUARY_INCREASE);
            }
        }
    }

    // Выводим результаты
    for (int i = 0; i < N; i++) {
        cout << "Сотрудник " << employees[i].surname << " " << employees[i].name << " " << employees[i].patronymic << endl;
        cout << "Отдел: " << employees[i].department << endl;
        cout << "Должность: " << employees[i].position << endl;
        cout << "Год рождения: " << employees[i].birthYear << endl;
        cout << "Зарплата: ";
        for (int j = 0; j < 12; j++) {
            cout << employees[i].salary[j] << " ";
        }
        cout << endl;
        cout << "Пол: " << employees[i].gender << endl;
        cout << endl;
    }

    return 0;
}
