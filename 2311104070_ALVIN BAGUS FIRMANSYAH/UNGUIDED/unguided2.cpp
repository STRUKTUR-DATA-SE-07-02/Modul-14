#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cout << "Masukkan jumlah simpul: ";
    cin >> n;

    cout << "Masukkan jumlah sisi: ";
    cin >> m;

    // Matriks adjacency untuk graf tidak berarah
    vector<vector<int>> adjMatrix(n, vector<int>(n, 0));

    cout << "Masukkan pasangan simpul (misal: 1 2):\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cout << "Pasangan simpul (u v): ";
        cin >> u >> v;

        // Karena simpul yang dimasukkan adalah 1-indexed, kita kurangi 1 untuk indexing 0
        adjMatrix[u - 1][v - 1] = 1;
        adjMatrix[v - 1][u - 1] = 1;  // Karena graf tidak berarah
    }

    cout << "Adjacency Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
