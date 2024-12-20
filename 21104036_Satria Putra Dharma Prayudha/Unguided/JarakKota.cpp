#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cout << "Silakan masukkan jumlah simpul: ";
    cin >> n;

    vector<string> nodes(n);
    cout << "Silakan masukkan nama simpul:\n";
    for (int i = 0; i < n; i++) {
        cout << "Simpul " << i + 1 << ": ";
        cin >> nodes[i];
    }

    vector<vector<int>> graph(n, vector<int>(n, 0));

    cout << "Silakan masukkan bobot antar simpul:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                cout << nodes[i] << " --> " << nodes[j] << ": ";
                cin >> graph[i][j];
            }
        }
    }

    cout << "\nMatriks Adjacency dengan Bobot:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
