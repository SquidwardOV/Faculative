#include <iostream>     // Подключаем библиотеку для ввода-вывода
#include <fstream>      // Подключаем библиотеку для работы с файлами
#include <vector>       // Подключаем библиотеку для работы с векторами
#include <algorithm>    // Подключаем библиотеку для работы с алгоритмами
#include <limits>       // Подключаем библиотеку для работы с числовыми пределами
#include <windows.h>    // Подключаем библиотеку для русификатора

using namespace std;

const int INF = INT_MAX; // Определяем бесконечность как максимально возможное значение int

// Функция для алгоритма Флойда-Уоршалла
void floydWarshall(vector<vector<int>>& dist, int n) {
    for (int k = 0; k < n; ++k) { // Проходим по всем промежуточным вершинам
        for (int i = 0; i < n; ++i) { // Проходим по всем начальным вершинам
            for (int j = 0; j < n; ++j) { // Проходим по всем конечным вершинам
                // Обновляем кратчайшее расстояние между вершинами i и j через вершину k, если найден путь короче
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

// Функция для проверки симметричности матрицы
bool isSymmetric(const vector<vector<int>>& dist, int n) {
    for (int i = 0; i < n; ++i) { // Проходим по всем строкам
        for (int j = 0; j < n; ++j) { // Проходим по всем столбцам
            // Если элемент [i][j] не равен элементу [j][i], матрица не симметрична
            if (dist[i][j] != dist[j][i]) {
                return false;
            }
        }
    }
    return true; // Если все элементы симметричны, возвращаем true
}

int main() {
    ifstream inputFile("input.txt"); // Открываем файл input.txt для чтения
    ofstream outputFile("output.txt"); // Открываем файл output.txt для записи

    if (!inputFile) { // Проверяем, удалось ли открыть файл
        cerr << "Error opening input file" << endl; // Выводим сообщение об ошибке
        return 1; // Завершаем программу с кодом ошибки
    }

    int n; // Переменная для хранения количества вершин
    inputFile >> n; // Считываем количество вершин из файла

    vector<vector<int>> dist(n, vector<int>(n)); // Создаем матрицу расстояний размером n x n
    for (int i = 0; i < n; ++i) { // Проходим по всем строкам
        for (int j = 0; j < n; ++j) { // Проходим по всем столбцам
            inputFile >> dist[i][j]; // Считываем значение из файла
            if (dist[i][j] == -1) { // Если значение равно -1, заменяем его на INF (бесконечность)
                dist[i][j] = INF;
            }
        }
    }

    inputFile.close(); // Закрываем файл input.txt

    bool symmetric = isSymmetric(dist, n); // Проверяем, является ли матрица симметричной
    floydWarshall(dist, n); // Применяем алгоритм Флойда-Уоршалла для нахождения кратчайших путей

    vector<int> eccentricity(n, 0); // Создаем вектор эксцентриситетов для каждой вершины
    int radius = INF; // Инициализируем радиус графа как бесконечность
    int diameter = 0; // Инициализируем диаметр графа как 0

    for (int i = 0; i < n; ++i) { // Проходим по всем вершинам
        for (int j = 0; j < n; ++j) { // Проходим по всем вершинам
            if (dist[i][j] != INF) { // Если расстояние не равно бесконечности
                eccentricity[i] = max(eccentricity[i], dist[i][j]); // Обновляем эксцентриситет вершины
            }
        }
        radius = min(radius, eccentricity[i]); // Обновляем радиус графа
        diameter = max(diameter, eccentricity[i]); // Обновляем диаметр графа
    }

    vector<int> centralVertices, peripheralVertices; // Векторы для центральных и периферийных вершин
    for (int i = 0; i < n; ++i) { // Проходим по всем вершинам
        if (eccentricity[i] == radius) { // Если эксцентриситет равен радиусу
            centralVertices.push_back(i + 1); // Добавляем вершину в центральные вершины
        }
        if (eccentricity[i] == diameter) { // Если эксцентриситет равен диаметру
            peripheralVertices.push_back(i + 1); // Добавляем вершину в периферийные вершины
        }
    }

    outputFile << "Тип графа: " << (symmetric ? "Неориентированный" : "Ориентированный") << endl; // Выводим тип графа
    outputFile << "Радиус: " << radius << endl; // Выводим радиус графа
    outputFile << "Диаметр: " << diameter << endl; // Выводим диаметр графа
    outputFile << "Центральные вершины: "; // Выводим центральные вершины
    for (int v : centralVertices) { // Проходим по всем центральным вершинам
        outputFile << v << " "; // Выводим центральную вершину
    }
    outputFile << endl;
    outputFile << "Переферийные вершины: "; // Выводим периферийные вершины
    for (int v : peripheralVertices) { // Проходим по всем периферийным вершинам
        outputFile << v << " "; // Выводим периферийную вершину
    }
    outputFile << endl;

    outputFile.close(); // Закрываем файл output.txt
    return 0; // Завершаем программу
}
