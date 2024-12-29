#include <iostream>
#include <vector>

using namespace std;

void displayMatrix(const vector<vector<int>>& matrix) {
    int n = matrix.size();
    cout << "Adjacency Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int nodes, edges;

    // Input jumlah simpul dan sisi
    cout << "Masukkan jumlah simpul: ";
    cin >> nodes;
    cout << "Masukkan jumlah sisi: ";
    cin >> edges;

    // Inisialisasi adjacency matrix
    vector<vector<int>> adjMatrix(nodes, vector<int>(nodes, 0));

    // Input pasangan simpul yang terhubung
    cout << "Masukkan pasangan simpul:\n";
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;

        // Karena graf tidak berarah, simetri adjacency matrix
        adjMatrix[u - 1][v - 1] = 1;
        adjMatrix[v - 1][u - 1] = 1;
    }

    // Tampilkan adjacency matrix
    displayMatrix(adjMatrix);

    return 0;
}
