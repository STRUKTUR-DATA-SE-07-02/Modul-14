#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cout << "Silakan masukan jumlah simpul: ";
    cin >> n;

    vector<string> vertices(n);
    cout << "Silakan masukan nama simpul" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Simpul " << i + 1 << ": ";
        cin >> vertices[i];
    }

    vector<vector<int>> graph(n, vector<int>(n));
    cout << "\nSilakan masukan bobot antar simpul" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << vertices[i] << " --> " << vertices[j] << ": ";
            cin >> graph[i][j];
        }
    }

    cout << "\n\t";
    for (const auto& vertex : vertices) {
        cout << vertex << "\t";
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << vertices[i] << "\t";
        for (int j = 0; j < n; j++) {
            cout << graph[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}