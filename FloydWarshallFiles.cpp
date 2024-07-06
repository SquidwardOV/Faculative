#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <fstream>
#include <windows.h>

using namespace std;

const int INF = INT_MAX;

void floydWarshall(vector<vector<int>>& dist, int V) {
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int main() {
    SetConsoleOutputCP(1251);
    ifstream inputFile("1.txt");
    if (!inputFile) {
        cerr << "Ошибка открытия файла!" << endl;
        return 1;
    }

    int V, E;
    inputFile >> V >> E;

    vector<vector<int>> dist(V, vector<int>(V, INF));

    for (int i = 0; i < V; i++) {
        dist[i][i] = 0;
    }

    for (int i = 0; i < E; i++) {
        int u, v, w;
        inputFile >> u >> v >> w;
        dist[u][v] = w;
        dist[v][u] = w; // если граф неориентированный
    }

    inputFile.close();

    floydWarshall(dist, V);

    // Вычисление эксцентриситета для каждой вершины
    vector<int> eccentricity(V, 0);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] != INF) {
                eccentricity[i] = max(eccentricity[i], dist[i][j]);
            }
        }
    }

    // Нахождение радиуса и диаметра
    int radius = INF;
    int diameter = 0;
    for (int i = 0; i < V; i++) {
        radius = min(radius, eccentricity[i]);
        diameter = max(diameter, eccentricity[i]);
    }

    // Нахождение центров и периферийных вершин
    vector<int> centers;
    vector<int> peripheralVertices;
    for (int i = 0; i < V; i++) {
        if (eccentricity[i] == radius) {
            centers.push_back(i);
        }
        if (eccentricity[i] == diameter) {
            peripheralVertices.push_back(i);
        }
    }

    // Вывод результатов
    cout << "Радиус графа: " << radius << endl;
    cout << "Диаметр графа: " << diameter << endl;
    cout << "Центральные вершины: ";
    for (int center : centers) {
        cout << center << " ";
    }
    cout << endl;
    cout << "Периферийные вершины: ";
    for (int peripheral : peripheralVertices) {
        cout << peripheral << " ";
    }
    cout << endl;

    return 0;
}
