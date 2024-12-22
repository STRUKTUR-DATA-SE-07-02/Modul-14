#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    int numCities;

    cout << "Silakan masukkan jumlah simpul : ";
    cin >> numCities;

    vector<string> cityNames(numCities);
    for (int i = 0; i < numCities; ++i) {
        cout << "Simpul " << i + 1 << " : ";
        cin >> cityNames[i];
    }

    vector<vector<int>> distances(numCities, vector<int>(numCities));

    cout << "Silakan masukkan bobot antar simpul" << endl;
    for (int i = 0; i < numCities; ++i) {
        for (int j = 0; j < numCities; ++j) {
            cout << cityNames[i] << "-->" << cityNames[j] << " = ";
            cin >> distances[i][j];
        }
    }

    cout << endl;
    cout << setw(10) << "";
    for (int i = 0; i < numCities; ++i) {
        cout << setw(10) << cityNames[i];
    }
    cout << endl;

    for (int i = 0; i < numCities; ++i) {
        cout << setw(10) << cityNames[i];
        for (int j = 0; j < numCities; ++j) {
            cout << setw(10) << distances[i][j];
        }
        cout << endl;
    }

    return 0;
}
