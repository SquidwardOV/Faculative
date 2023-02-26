#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

struct Passenger {
    string surname;
    string initials;
    double total_weight;
    int num_items;
};

int main() {
    int n;
    cout << "Введите количество пассажиров: ";
    cin >> n;
    cin.ignore(); // сбросить символ перевода строки во входном буфере

    vector<Passenger> passengers;
    double total_weight = 0.0;
    int total_items = 0;

    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);

        istringstream iss(line);

        Passenger p;
        iss >> p.surname >> p.initials >> p.total_weight >> p.num_items;

        passengers.push_back(p);

        total_weight += p.total_weight;
        total_items += p.num_items;
    }

    double average_weight = total_weight / total_items;

    for (const auto& p : passengers) {
        double item_weight = p.total_weight / p.num_items;
        if (item_weight > average_weight) {
            cout << p.surname << " " << p.initials << endl;
        }
    }

    return 0;
}
