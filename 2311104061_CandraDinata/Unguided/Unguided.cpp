#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    int jumlahSimpul;
    cout << "Masukkan jumlah simpul: ";
    cin >> jumlahSimpul;

    vector<string> namaSimpul(jumlahSimpul);
    cout << "Masukkan nama setiap simpul:\n";
    for (int i = 0; i < jumlahSimpul; ++i) {
        cout << "Nama simpul ke-" << i + 1 << ": ";
        cin >> namaSimpul[i];
    }

    vector<vector<int>> matriksBobot(jumlahSimpul, vector<int>(jumlahSimpul));
    cout << "Masukkan bobot antar simpul:\n";
    for (int baris = 0; baris < jumlahSimpul; ++baris) {
        for (int kolom = 0; kolom < jumlahSimpul; ++kolom) {
            cout << namaSimpul[baris] << " --> " << namaSimpul[kolom] << " = ";
            cin >> matriksBobot[baris][kolom];
        }
    }

    // Cetak header matriks
    cout << "\n" << setw(10) << " ";
    for (const auto& nama : namaSimpul) {
        cout << setw(10) << nama;
    }
    cout << endl;

    // Cetak isi matriks
    for (int baris = 0; baris < jumlahSimpul; ++baris) {
        cout << setw(10) << namaSimpul[baris];
        for (int kolom = 0; kolom < jumlahSimpul; ++kolom) {
            cout << setw(10) << matriksBobot[baris][kolom];
        }
        cout << endl;
    }

    return 0;
}