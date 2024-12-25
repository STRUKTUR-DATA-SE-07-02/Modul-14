#include <iostream>
#include <vector>

using namespace std;

void adjacencyMatrix() {
    int nodes, edges;
    cout << "Masukkan jumlah simpul: ";
    cin >> nodes;
    cout << "Masukkan jumlah sisi: ";
    cin >> edges;

    // Membuat adjacency matrix
    vector<vector<int>> adjMatrix(nodes, vector<int>(nodes, 0));

    cout << "Masukkan pasangan simpul: " << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adjMatrix[u - 1][v - 1] = 1;
        adjMatrix[v - 1][u - 1] = 1; // Karena graf tidak berarah
    }

    // Menampilkan adjacency matrix
    cout << "Adjacency Matrix:" << endl;
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    adjacencyMatrix();
    return 0;
}
