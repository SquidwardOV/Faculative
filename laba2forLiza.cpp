#include <iostream>
#include <fstream>
#include <string>

struct Employee {
    std::string surname;
    std::string name;
    std::string patronymic;
    std::string department;
    std::string position;
    int birth_year;
    float monthly_salary[12];
    char gender;
};

int main() {
    std::ifstream input("employees.txt");
    int N;
    std::string department_name;
    input >> N >> department_name;

    Employee employees[N];
    for (int i = 0; i < N; i++) {
        input >> employees[i].surname >> employees[i].name >> employees[i].patronymic
              >> employees[i].department >> employees[i].position >> employees[i].birth_year
              >> employees[i].monthly_salary[0] >> employees[i].monthly_salary[1]
              >> employees[i].monthly_salary[2] >> employees[i].monthly_salary[3]
              >> employees[i].monthly_salary[4] >> employees[i].monthly_salary[5]
              >> employees[i].monthly_salary[6] >> employees[i].monthly_salary[7]
              >> employees[i].monthly_salary[8] >> employees[i].monthly_salary[9]
              >> employees[i].monthly_salary[10] >> employees[i].monthly_salary[11]
              >> employees[i].gender;
    }

    for (int i = 0; i < N; i++) {
        int age = 2023 - employees[i].birth_year;
        if (age < 60 && employees[i].department == department_name) {
            employees[i].monthly_salary[0] *= 1.15;
        }
    }

    for (int i = 0; i < N; i++) {
        std::cout << employees[i].surname << " " << employees[i].name << " " << employees[i].patronymic
                  << " " << employees[i].department << " " << employees[i].position << " "
                  << employees[i].birth_year << " ";
        for (int j = 0; j < 12; j++) {
            std::cout << employees[i].monthly_salary[j] << " ";
        }
        std::cout << employees[i].gender << std::endl;
    }

    return 0;
}
