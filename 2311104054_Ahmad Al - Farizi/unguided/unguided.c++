#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int jumlahSimpul;

    // Memasukkan jumlah simpul
    cout << "Silakan masukan jumlah simpul: ";
    cin >> jumlahSimpul;

    vector<string> simpul(jumlahSimpul);

    // Memasukkan nama-nama simpul
    for (int i = 0; i < jumlahSimpul; i++) {
        cout << "Simpul " << i + 1 << ": ";
        cin >> simpul[i];
    }

    // Inisialisasi matriks bobot (adjacency matrix)
    vector<vector<int>> matriks(jumlahSimpul, vector<int>(jumlahSimpul, 0));

    // Memasukkan bobot antar simpul
    for (int i = 0; i < jumlahSimpul; i++) {
        for (int j = 0; j < jumlahSimpul; j++) {
            cout << simpul[i] << " --> " << simpul[j] << " = ";
            cin >> matriks[i][j];
        }
    }

    // Menampilkan matriks bobot
    cout << "\nMatriks Bobot:\n";
    cout << setw(8) << " ";
    for (const auto& s : simpul) {
        cout << setw(8) << s;
    }
    cout << endl;

    for (int i = 0; i < jumlahSimpul; i++) {
        cout << setw(8) << simpul[i];
        for (int j = 0; j < jumlahSimpul; j++) {
            cout << setw(8) << matriks[i][j];
        }
        cout << endl;
    }

    return 0;
}
