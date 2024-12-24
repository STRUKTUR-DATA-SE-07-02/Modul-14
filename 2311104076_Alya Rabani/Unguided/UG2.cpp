#include <iostream>
using namespace std;

int main() {
    int jumlahSimpul, jumlahSisi;
    int adjacencyMatrix[100][100] = {0}; // Inisialisasi matrix dengan 0
    
    // Input jumlah simpul
    cout << "Masukkan jumlah simpul: ";
    cin >> jumlahSimpul;
    
    // Input jumlah sisi
    cout << "Masukkan jumlah sisi: ";
    cin >> jumlahSisi;
    
    // Input pasangan simpul yang terhubung
    cout << "Masukkan pasangan simpul: " << endl;
    for(int i = 0; i < jumlahSisi; i++) {
        int simpul1, simpul2;
        cin >> simpul1 >> simpul2;
        
        // Karena graf tidak berarah, kita perlu mengisi kedua arah
        // Kurangi 1 dari input karena array dimulai dari 0
        adjacencyMatrix[simpul1-1][simpul2-1] = 1;
        adjacencyMatrix[simpul2-1][simpul1-1] = 1;
    }
    
    // Menampilkan adjacency matrix
    cout << "\nAdjacency Matrix:" << endl;
    for(int i = 0; i < jumlahSimpul; i++) {
        for(int j = 0; j < jumlahSimpul; j++) {
            cout << adjacencyMatrix[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}