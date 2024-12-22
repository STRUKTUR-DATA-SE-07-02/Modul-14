#include <iostream>
#include <vector>

using namespace std;

int main() {
    int V, E;
    cout << "Masukkan jumlah simpul: ";
    cin >> V;
    cout << "Masukkan jumlah sisi: ";
    cin >> E;

    // Membuat adjacency matrix dengan ukuran VxV dan menginisialisasi dengan 0
    vector<vector<int>> adjacencyMatrix(V, vector<int>(V, 0));

    cout << "Masukkan pasangan simpul:" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        // Karena simpul mulai dari 1, bukan 0, kurangi 1 untuk indeks matriks
        u--;
        v--;
        adjacencyMatrix[u][v] = 1;
        adjacencyMatrix[v][u] = 1; // Graf tidak berarah
    }

    // Menampilkan adjacency matrix
    cout << "Adjacency Matrix:" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << adjacencyMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}