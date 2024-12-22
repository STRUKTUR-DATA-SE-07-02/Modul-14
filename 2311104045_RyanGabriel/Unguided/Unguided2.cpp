#include <iostream>
#include <vector>

using namespace std;

// Fungsi untuk mencetak adjacency matrix
void printMatrix(const vector<vector<int>>& matrix) {
    cout << "Adjacency Matrix:\n";
    for (const auto& row : matrix) {
        for (int value : row) {
            cout << value << " ";
        }
        cout << endl;
    }
}

int main() {
    int numNodes, numEdges;

    // Input jumlah simpul dan sisi
    cout << "Masukkan jumlah simpul: ";
    cin >> numNodes;
    cout << "Masukkan jumlah sisi: ";
    cin >> numEdges;

    // Inisialisasi adjacency matrix dengan 0
    vector<vector<int>> adjacencyMatrix(numNodes, vector<int>(numNodes, 0));

    cout << "Masukkan pasangan simpul:\n";
    for (int i = 0; i < numEdges; ++i) {
        int u, v;
        cin >> u >> v;

        // Karena graf tidak berarah, tandai kedua arah
        adjacencyMatrix[u - 1][v - 1] = 1;
        adjacencyMatrix[v - 1][u - 1] = 1;
    }

    // Cetak adjacency matrix
    printMatrix(adjacencyMatrix);

    return 0;
}