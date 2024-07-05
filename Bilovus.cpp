#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

void dfs1(int v, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& order) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) {
            dfs1(u, adj, visited, order);
        }
    }
    order.push(v);
}

void dfs2(int v, vector<vector<int>>& transpose, vector<bool>& visited, vector<int>& component) {
    visited[v] = true;
    component.push_back(v);
    for (int u : transpose[v]) {
        if (!visited[u]) {
            dfs2(u, transpose, visited, component);
        }
    }
}

vector<vector<int>> findSCCs(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> visited(n, false);
    stack<int> order;

    // Первый обход графа для построения порядка вершин
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs1(i, adj, visited, order);
        }
    }

    // Построение транспонированного графа
    vector<vector<int>> transpose(n);
    for (int v = 0; v < n; ++v) {
        for (int u : adj[v]) {
            transpose[u].push_back(v);
        }
    }

    fill(visited.begin(), visited.end(), false);
    vector<vector<int>> sccs;

    // Второй обход графа по порядку вершин
    while (!order.empty()) {
        int v = order.top();
        order.pop();
        if (!visited[v]) {
            vector<int> component;
            dfs2(v, transpose, visited, component);
            sccs.push_back(component);
        }
    }

    return sccs;
}

int main() {
    int n;
    cout << "Введите количество вершин: ";
    cin >> n;

    vector<vector<int>> adj(n);
    cout << "Введите матрицу смежности (вводите 0 или 1):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int edge;
            cin >> edge;
            if (edge == 1) {
                adj[i].push_back(j);
            }
        }
    }

    vector<vector<int>> sccs = findSCCs(adj);

    cout << "Сильные компоненты связности:\n";
    for (const auto& component : sccs) {
        for (int v : component) {
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}
