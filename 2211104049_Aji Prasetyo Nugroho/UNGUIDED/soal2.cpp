#include <iostream>
#include <vector>
using namespace std;

int main() {
    int vertices, edges;
    
    // Input jumlah simpul
    cout << "Masukkan jumlah simpul: ";
    cin >> vertices;
    
    // Input jumlah sisi
    cout << "Masukkan jumlah sisi: ";
    cin >> edges;
    
    // Inisialisasi matrix adjacency dengan 0
    vector<vector<int>> adjMatrix(vertices, vector<int>(vertices, 0));
    
    cout << "Masukkan pasangan simpul:\n";
    for(int i = 0; i < edges; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        // Karena graf tidak berarah, set kedua arah
        adjMatrix[v1-1][v2-1] = 1;
        adjMatrix[v2-1][v1-1] = 1;
    }
    
    // Tampilkan matrix adjacency
    cout << "\nAdjacency Matrix:\n";
    for(int i = 0; i < vertices; i++) {
        for(int j = 0; j < vertices; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}