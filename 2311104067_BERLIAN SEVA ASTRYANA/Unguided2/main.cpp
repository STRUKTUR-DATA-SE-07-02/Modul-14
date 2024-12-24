#include <iostream>
#include <vector>

using namespace std;

int main() {
    int jumlah_simpul, jumlah_sisi;

    // Input jumlah simpul dan sisi
    cout << "Masukkan jumlah simpul: ";
    cin >> jumlah_simpul;

    cout << "Masukkan jumlah sisi: ";
    cin >> jumlah_sisi;

    // Matriks adjacency diinisialisasi dengan 0
    vector<vector<int>> adjacency_matrix(jumlah_simpul, vector<int>(jumlah_simpul, 0));

    // Input pasangan simpul yang terhubung
    cout << "Masukkan pasangan simpul:" << endl;
    for (int i = 0; i < jumlah_sisi; ++i) {
        int simpul1, simpul2;
        cin >> simpul1 >> simpul2;

        // Karena graf tidak berarah, tandai kedua arah
        adjacency_matrix[simpul1 - 1][simpul2 - 1] = 1;
        adjacency_matrix[simpul2 - 1][simpul1 - 1] = 1;
    }

    // Output adjacency matrix
    cout << "Adjacency Matrix:" << endl;
    for (int i = 0; i < jumlah_simpul; ++i) {
        for (int j = 0; j < jumlah_simpul; ++j) {
            cout << adjacency_matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
