#include <iostream>
using namespace std;

int main() {
    int jumlahSimpul, jumlahSisi;
    
    // Input jumlah simpul dan sisi
    cout << "Masukkan jumlah simpul: ";
    cin >> jumlahSimpul;
    cout << "Masukkan jumlah sisi: ";
    cin >> jumlahSisi;
    
    // Inisialisasi adjacency matrix dengan 0
    int adjacencyMatrix[10][10] = {0}; // Asumsi maksimal 10 simpul
    
    cout << "Masukkan pasangan simpul:\n";
    for(int i = 0; i < jumlahSisi; i++) {
        int simpul1, simpul2;
        cin >> simpul1 >> simpul2;
        
        // Karena graf tidak berarah, kita set kedua arah
        adjacencyMatrix[simpul1-1][simpul2-1] = 1;
        adjacencyMatrix[simpul2-1][simpul1-1] = 1;
    }
    
    // Menampilkan adjacency matrix
    cout << "\nAdjacency Matrix:\n";
    for(int i = 0; i < jumlahSimpul; i++) {
        for(int j = 0; j < jumlahSimpul; j++) {
            cout << adjacencyMatrix[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}