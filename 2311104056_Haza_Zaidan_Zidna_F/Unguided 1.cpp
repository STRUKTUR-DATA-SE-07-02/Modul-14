#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    int V;
    cout << "Silakan masukan jumlah simpul : ";
    cin >> V;

    vector<string> cities(V);
    cout << "Silakan masukan nama simpul:\n";
    for (int i = 0; i < V; i++) {
        cout << "Simpul " << i + 1 << " : ";
        cin >> cities[i];
    }

    vector<vector<int>> graph(V, vector<int>(V, 0));
    cout << "Silakan masukkan bobot antar simpul \n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << cities[i] << "--> " << cities[j] << " = ";
            cin >> graph[i][j];
        }
    }

    // Print header for the matrix
    cout << "\n" << setw(8) << " ";
    for (int i = 0; i < V; i++) {
        cout << setw(8) << cities[i];
    }
    cout << endl;

    // Print matrix
    for (int i = 0; i < V; i++) {
        cout << setw(8) << cities[i];
        for (int j = 0; j < V; j++) {
            cout << setw(8) << graph[i][j];
        }
        cout << endl;
    }

    return 0;
}