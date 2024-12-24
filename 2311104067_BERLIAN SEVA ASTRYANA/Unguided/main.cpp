#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // Untuk pengaturan format output

using namespace std;

int main() {
    int jumlah_simpul;

    // Meminta jumlah simpul
    cout << "Silakan masukan jumlah simpul: ";
    cin >> jumlah_simpul;

    vector<string> simpul(jumlah_simpul); // Menyimpan nama simpul
    vector<vector<int>> graph(jumlah_simpul, vector<int>(jumlah_simpul, 0)); // Matriks adjacency

    // Meminta nama simpul
    cout << "\nSilakan masukan nama simpul" << endl;
    for (int i = 0; i < jumlah_simpul; ++i) {
        cout << "Simpul " << i + 1 << ": ";
        cin >> simpul[i];
    }

    // Meminta bobot antar simpul
    cout << "\nSilakan masukkan bobot antar simpul" << endl;
    for (int i = 0; i < jumlah_simpul; ++i) {
        for (int j = 0; j < jumlah_simpul; ++j) {
            cout << simpul[i] << "--> " << simpul[j] << " = ";
            cin >> graph[i][j];
        }
    }

    // Output header tabel
    cout << "\n\t";
    for (const auto& s : simpul) {
        cout << setw(10) << s; // Setiap nama simpul memiliki lebar kolom 10
    }
    cout << endl;

    // Output matriks adjacency
    for (int i = 0; i < jumlah_simpul; ++i) {
        cout << setw(10) << simpul[i]; // Nama baris (simpul)
        for (int j = 0; j < jumlah_simpul; ++j) {
            cout << setw(10) << graph[i][j]; // Bobot antar simpul
        }
        cout << endl;
    }

    return 0;
}
