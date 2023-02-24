#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int main() {
    // Вектор, в котором будут храниться среднесуточные температуры за каждый день марта
    std::vector<int> temperatures(31, 0);

    // Ввод температурных данных
    std::string line;
    while (std::getline(std::cin, line)) {
        int day, morning_temp, day_temp, evening_temp, night_temp;
        std::stringstream ss(line);
        ss >> day;
        // Пропускаем символы до "утро"
        while (ss.get() != ':');
        ss >> morning_temp;
        // Пропускаем символы до "день"
        while (ss.get() != ';');
        ss >> day_temp;
        // Пропускаем символы до "вечер"
        while (ss.get() != ';');
        ss >> evening_temp;
        // Пропускаем символы до "ночь"
        while (ss.get() != ';');
        ss >> night_temp;

        // Вычисляем среднесуточную температуру и сохраняем ее в векторе
        int avg_temp = (morning_temp + day_temp + evening_temp + night_temp) / 4;
        temperatures[day - 1] = avg_temp;
    }

    // Вычисляем среднюю температуру за март
    int total_avg_temp = 0;
    for (int temp : temperatures) {
        total_avg_temp += temp;
    }
    int avg_temp_march = total_avg_temp / 31;

    // Вывод дней последней декады, удовлетворяющих условию
    for (int day = 21; day <= 31; day++) {
        if (temperatures[day - 1] > avg_temp_march) {
            std::cout << day << " ";
        }
    }

    return 0;
}
