#include <iostream>
#include <cmath>

struct Ball {
    double x;
    double y;
    double z;
    double radius;
    std::string color;
};

int main()
{
    Ball balls[50];
    double minDist = std::numeric_limits<double>::max();
    int minBallIdx = -1;
    // Заполняем массив шаров
    for (int i = 0; i < 50; i++) {
        balls[i].x = rand() % 100;
        balls[i].y = rand() % 100;
        balls[i].z = rand() % 100;
        balls[i].radius = rand() % 10;
        balls[i].color = "blue";
        // Находим шар с минимальным расстоянием до начала координат
        double dist = std::sqrt(balls[i].x * balls[i].x + balls[i].y * balls[i].y + balls[i].z * balls[i].z);
        if (dist < minDist) {
            minDist = dist;
            minBallIdx = i;
        }
    }
    // Выводим цвет и координаты центра шара, расположенного к началу координат ближе всех
    std::cout << "Color: " << balls[minBallIdx].color << std::endl;
    std::cout << "Center coordinates: (" << balls[minBallIdx].x << ", " << balls[minBallIdx].y << ", " << balls[minBallIdx].z << ")" << std::endl;
    return 0;
}
