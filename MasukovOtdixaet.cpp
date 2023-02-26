#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.get();
    
    vector<string> surnames;
    vector<double> weights;
    double total_weight = 0;
    for (int i = 0; i < n; i++)
    {
        string line;
        getline(cin, line);
        stringstream ss(line);
        string surname;
        double weight, items_count;
        ss >> surname >> weight >> items_count;
        surnames.push_back(surname);
        weights.push_back(weight / items_count);
        total_weight += weight;
    }
    
    double avg_weight = total_weight / n;
    for (int i = 0; i < n; i++)
    {
        if (weights[i] > avg_weight)
            cout << surnames[i] << endl;
    }
    return 0;
}
