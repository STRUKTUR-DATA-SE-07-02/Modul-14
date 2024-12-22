#include <iostream>
#include <vector>

using namespace std;

int main() {
    int jumlahSimpul, jumlahSisi;
    cout << "Masukkan jumlah simpul: ";
    cin >> jumlahSimpul;
    cout << "Masukkan jumlah sisi: ";
    cin >> jumlahSisi;

    // Inisialisasi adjacency matrix dengan ukuran jumlahSimpul x jumlahSimpul dan nilai awal 0
    vector<vector<int>> adjacencyMatrix(jumlahSimpul, vector<int>(jumlahSimpul, 0));

    cout << "Masukkan pasangan simpul yang terhubung oleh sisi (contoh: 1 2):" << endl;
    for (int i = 0; i < jumlahSisi; ++i) {
        int simpul1, simpul2;
        cin >> simpul1 >> simpul2;

        // Kurangi 1 dari simpul1 dan simpul2 untuk mengkonversi ke indeks array (dimulai dari 0)
        simpul1--;
        simpul2--;

        // Karena graf tidak berarah, kita menambahkan sisi di kedua arah
        adjacencyMatrix[simpul1][simpul2] = 1;
        adjacencyMatrix[simpul2][simpul1] = 1;
    }

    // Tampilkan adjacency matrix
    cout << "Adjacency Matrix:" << endl;
    for (int i = 0; i < jumlahSimpul; ++i) {
        for (int j = 0; j < jumlahSimpul; ++j) {
            cout << adjacencyMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
