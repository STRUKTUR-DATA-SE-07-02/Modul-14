#include <iostream>
#include <vector>

using namespace std;

int main() {
    int jumlahSimpul, jumlahSisi;
    cout << "Masukkan total simpul: ";
    cin >> jumlahSimpul;
    cout << "Masukkan total sisi: ";
    cin >> jumlahSisi;

    // Membuat matriks ketetanggaan dengan ukuran NxN, diinisialisasi ke 0
    vector<vector<int>> matriksKetetanggaan(jumlahSimpul, vector<int>(jumlahSimpul, 0));

    cout << "Masukkan pasangan simpul yang terhubung:" << endl;
    for (int i = 0; i < jumlahSisi; ++i) {
        int simpul1, simpul2;
        cin >> simpul1 >> simpul2;
        // Menyesuaikan indeks karena input dimulai dari 1
        simpul1--;
        simpul2--;
        matriksKetetanggaan[simpul1][simpul2] = 1;
        matriksKetetanggaan[simpul2][simpul1] = 1; // Untuk graf tidak berarah
    }

    // Menampilkan matriks ketetanggaan
    cout << "Matriks Ketetanggaan:" << endl;
    for (const auto& baris : matriksKetetanggaan) {
        for (int elemen : baris) {
            cout << elemen << " ";
        }
        cout << endl;
    }

    return 0;
}