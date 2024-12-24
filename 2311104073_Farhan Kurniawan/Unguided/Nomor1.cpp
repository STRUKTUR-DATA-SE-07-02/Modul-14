#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    int jumlahSimpul;

    // Meminta jumlah simpul dari pengguna
    cout << "Silakan masukkan jumlah simpul: ";
    cin >> jumlahSimpul;

    vector<string> simpul(jumlahSimpul);
    vector<vector<int>> bobot(jumlahSimpul, vector<int>(jumlahSimpul, 0));

    // Meminta nama simpul
    for (int i = 0; i < jumlahSimpul; i++) {
        cout << "Silakan masukkan nama simpul " << i + 1 << ": ";
        cin >> simpul[i];
    }

    // Meminta bobot antar simpul
    cout << "Silakan masukkan bobot antar simpul:\n";
    for (int i = 0; i < jumlahSimpul; i++) {
        for (int j = 0; j < jumlahSimpul; j++) {
            if (i == j) {
                bobot[i][j] = 0; // Bobot dari simpul ke dirinya sendiri adalah 0
            } else {
                cout << simpul[i] << " --> " << simpul[j] << ": ";
                cin >> bobot[i][j];
            }
        }
    }

    // Menampilkan matriks bobot
    cout << "\nMatriks Bobot:\n";
    cout << setw(10) << " ";
    for (const auto& namaSimpul : simpul) {
        cout << setw(10) << namaSimpul;
    }
    cout << endl;

    for (int i = 0; i < jumlahSimpul; i++) {
        cout << setw(10) << simpul[i];
        for (int j = 0; j < jumlahSimpul; j++) {
            cout << setw(10) << bobot[i][j];
        }
        cout << endl;
    }

    return 0;
}
