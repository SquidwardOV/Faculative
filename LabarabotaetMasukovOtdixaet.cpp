#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <windows.h>

using namespace std;

struct Passenger {
    string surname;
    string kgs;
    string initials;
    float total_weight;
    int number_of_items;
};

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int n;
    cout << "Введите количество пассажиров: ";
    cin >> n;

    vector<Passenger> passengers(n);

    // Считываем информацию о пассажирах
    for (int i = 0; i < n; i++) {
        Passenger p;
        cin >> p.surname >> p.initials >> p.total_weight >> p.kgs >> p.number_of_items;
        passengers[i] = p;
    }

    // Вычисляем средний вес одной вещи багажа всех пассажиров
    float avg_weight_per_item = 0;
    for (const Passenger& p : passengers) {
        avg_weight_per_item += p.total_weight / p.number_of_items;
    }
    avg_weight_per_item /= n;

    // Выбираем пассажиров, у которых средний вес одной вещи багажа больше среднего
    vector<string> selected_passengers;
    for (const Passenger& p : passengers) {
        float avg_weight_per_item_of_passenger = p.total_weight / p.number_of_items;
        if (avg_weight_per_item_of_passenger > avg_weight_per_item) {
            selected_passengers.push_back(p.surname);
        }
    }

    // Сортируем фамилии пассажиров и выводим их
    sort(selected_passengers.begin(), selected_passengers.end());
    for (const string& surname : selected_passengers) {
        cout << surname << endl;
    }

    return 0;
}
