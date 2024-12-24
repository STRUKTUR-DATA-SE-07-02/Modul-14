#include <iostream>
#include <string>

using namespace std;

int main() {
    int jumlahSimpul;

    // Input jumlah simpul
    cout << "Silakan masukkan jumlah simpul: ";
    cin >> jumlahSimpul;

    // Membuat array 2D untuk menyimpan matriks ketetanggaan
    int matriks[jumlahSimpul][jumlahSimpul];

    // Inisialisasi semua elemen matriks menjadi 0
    for (int i = 0; i < jumlahSimpul; i++) {
        for (int j = 0; j < jumlahSimpul; j++) {
            matriks[i][j] = 0;
        }
    }

    // Input nama simpul (untuk tampilan, tidak digunakan dalam perhitungan)
    string namaSimpul[jumlahSimpul];
    cout << "Silakan masukkan nama simpul" << endl;
    for (int i = 0; i < jumlahSimpul; i++) {
        cout << "Simpul " << i+1 << ": ";
        cin >> namaSimpul[i];
    }

    // Input bobot antar simpul
    cout << "Silakan masukkan bobot antar simpul" << endl;
    for (int i = 0; i < jumlahSimpul; i++) {
        for (int j = 0; j < jumlahSimpul; j++) {
            cout << namaSimpul[i] << "-->" << namaSimpul[j] << " = ";
            cin >> matriks[i][j];
        }
    }

    // Menampilkan matriks ketetanggaan
    cout << endl;
    for (int i = 0; i < jumlahSimpul; i++) {
        cout << namaSimpul[i];
        for (int j = 0; j < jumlahSimpul; j++) {
            cout << "\t" << matriks[i][j];
        }
        cout << endl;
    }

    return 0;
}
