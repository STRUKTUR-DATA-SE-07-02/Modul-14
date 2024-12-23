#include <iostream>
#include <vector>

using namespace std;

int main() {
    int jumlahSimpul, jumlahSisi;
    cout << "Masukkan jumlah simpul: ";
    cin >> jumlahSimpul;
    cout << "Masukkan jumlah sisi: ";
    cin >> jumlahSisi;
    
    vector<vector<int>> adjacencyMatrix(jumlahSimpul, vector<int>(jumlahSimpul, 0));
    
    cout << "Masukkan pasangan simpul:\n";
    for (int i = 0; i < jumlahSisi; ++i) {
        int u, v;
        cin >> u >> v;
        
        adjacencyMatrix[u - 1][v - 1] = 1;
        adjacencyMatrix[v - 1][u - 1] = 1;
    }
    
    cout << "Adjacency Matrix:\n";
    for (int i = 0; i < jumlahSimpul; ++i) {
        for (int j = 0; j < jumlahSimpul; ++j) {
            cout << adjacencyMatrix[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
