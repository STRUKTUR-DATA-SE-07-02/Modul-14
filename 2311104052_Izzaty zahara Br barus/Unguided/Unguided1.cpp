#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    int numCities;

    cout << "Silakan masukkan jumlah simpul: ";
    cin >> numCities;

    vector<string> cityNames(numCities);
    vector<vector<int>> adjacencyMatrix(numCities, vector<int>(numCities, 0));

    for (int i = 0; i < numCities; ++i) {
        cout << "Simpul " << i + 1 << ": ";
        cin >> cityNames[i];
    }

    cout << "Silakan masukkan bobot antar simpul:" << endl;
    for (int i = 0; i < numCities; ++i) {
        for (int j = 0; j < numCities; ++j) {
            cout << cityNames[i] << " --> " << cityNames[j] << " = ";
            cin >> adjacencyMatrix[i][j];
        }
    }

    cout << endl << "Adjacency Matrix:" << endl;
    cout << setw(8) << " ";
    for (const auto &name : cityNames) {
        cout << setw(8) << name;
    }
    cout << endl;

    for (int i = 0; i < numCities; ++i) {
        cout << setw(8) << cityNames[i];
        for (int j = 0; j < numCities; ++j) {
            cout << setw(8) << adjacencyMatrix[i][j];
        }
        cout << endl;
    }

    return 0;
}
