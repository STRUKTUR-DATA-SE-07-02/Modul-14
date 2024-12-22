#include <iostream>
#include <vector>
using namespace std;

int main() {
    int numVertices, numEdges;

    // Memasukkan jumlah simpul dan sisi
    cout << "Masukkan jumlah simpul: ";
    cin >> numVertices;
    cout << "Masukkan jumlah sisi: ";
    cin >> numEdges;

    // Inisialisasi adjacency matrix
    vector<vector<int>> adjMatrix(numVertices, vector<int>(numVertices, 0));

    cout << "Masukkan pasangan simpul: " << endl;
    for (int i = 0; i < numEdges; ++i) {
        int u, v;
        cin >> u >> v;

        // Karena graf tidak berarah, tandai kedua arah dalam adjacency matrix
        adjMatrix[u - 1][v - 1] = 1;
        adjMatrix[v - 1][u - 1] = 1;
    }

    // Menampilkan adjacency matrix
    cout << "Adjacency Matrix:" << endl;
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
