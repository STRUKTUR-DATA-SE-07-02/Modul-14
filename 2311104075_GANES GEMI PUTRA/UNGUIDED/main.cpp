#include <iostream>
#include <vector>
using namespace std;

// Fungsi untuk membuat adjacency matrix
void createAdjMatrix(int nodes, int edges, vector<vector<int>>& adjMatrix) {
    cout << "Masukkan pasangan simpul yang terhubung:\n";
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;  // Input pasangan simpul
        adjMatrix[u - 1][v - 1] = 1; // Tandai hubungan di adjacency matrix
        adjMatrix[v - 1][u - 1] = 1; // Karena graf tidak berarah
    }
}

// Fungsi untuk mencetak adjacency matrix
void printAdjMatrix(const vector<vector<int>>& adjMatrix) {
    cout << "\nAdjacency Matrix:\n";
    for (const auto& row : adjMatrix) {
        for (int val : row) {
            cout << val << " ";
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

    // Inisialisasi adjacency matrix dengan ukuran nodes x nodes
    vector<vector<int>> adjMatrix(nodes, vector<int>(nodes, 0));

    // Buat adjacency matrix berdasarkan input user
    createAdjMatrix(nodes, edges, adjMatrix);

    // Tampilkan adjacency matrix
    printAdjMatrix(adjMatrix);

    return 0;
}
