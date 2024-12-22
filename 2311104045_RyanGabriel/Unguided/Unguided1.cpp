#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cout << "Silakan masukkan jumlah simpul: ";
    cin >> n;

    vector<string> nodes(n);
    cout << "Silakan masukkan nama simpul:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Simpul " << i + 1 << ": ";
        cin >> nodes[i];
    }

    vector<vector<int>> adjacencyMatrix(n, vector<int>(n, 0));
    cout << "Silakan masukkan bobot antar simpul:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << nodes[i] << " --> " << nodes[j] << " = ";
            cin >> adjacencyMatrix[i][j];
        }
    }

    cout << "\nAdjacency Matrix:\n";
    cout << setw(10) << "";
    for (const string &node : nodes) {
        cout << setw(10) << node;
    }
    cout << "\n";

    for (int i = 0; i < n; ++i) {
        cout << setw(10) << nodes[i];
        for (int j = 0; j < n; ++j) {
            cout << setw(10) << adjacencyMatrix[i][j];
        }
        cout << "\n";
    }

    return 0;
}