#include <iostream>
#include <vector>

using namespace std;

int main() {
    int vertices, edges;
    
    // Input jumlah simpul dan sisi
    cout << "Masukkan jumlah simpul: ";
    cin >> vertices;
    cout << "Masukkan jumlah sisi: ";
    cin >> edges;

    // Membuat matriks ketetanggaan
    vector<vector<int>> adjacencyMatrix(vertices, vector<int>(vertices, 0));

    cout << "Masukkan pasangan simpul yang terhubung:\n";
    for (int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;
        adjacencyMatrix[u - 1][v - 1] = 1;
        adjacencyMatrix[v - 1][u - 1] = 1; // Karena graf tidak berarah
    }

    // Menampilkan adjacency matrix
    cout << "Adjacency Matrix:\n";
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            cout << adjacencyMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
