#include <iostream>
#include <vector>

using namespace std;

int main() {
    int nodes, edges;

    // Input jumlah simpul dan sisi
    cout << "Masukkan jumlah simpul: ";
    cin >> nodes;
    cout << "Masukkan jumlah sisi: ";
    cin >> edges;

    // Inisialisasi adjacency matrix dengan nol
    vector<vector<int>> adjacencyMatrix(nodes, vector<int>(nodes, 0));

    // Input pasangan simpul yang terhubung
    cout << "Masukkan pasangan simpul:" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;

        // Asumsikan simpul mulai dari 1, sesuaikan dengan indeks array (mulai dari 0)
        adjacencyMatrix[u - 1][v - 1] = 1;
        adjacencyMatrix[v - 1][u - 1] = 1; // Karena graf tidak berarah
    }

    // Menampilkan adjacency matrix
    cout << "Adjacency Matrix:" << endl;
    for (const auto& row : adjacencyMatrix) {
        for (const auto& value : row) {
            cout << value << " ";
        }
        cout << endl;
    }

    return 0;
}
