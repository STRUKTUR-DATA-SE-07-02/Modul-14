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
    cout << "Silakan masukkan nama simpul:\n";
    for (int i = 0; i < jumlahSimpul; i++) {
        cout << "Simpul " << i + 1 << ": ";
        cin >> namaSimpul[i];
    }
    vector<vector<int>> adjacencyMatrix(jumlahSimpul, vector<int>(jumlahSimpul, 0));
    cout << "Silakan masukkan bobot antar simpul (gunakan 0 jika tidak ada hubungan):\n";
    for (int i = 0; i < jumlahSimpul; i++) {
        for (int j = 0; j < jumlahSimpul; j++) {
            if (i == j) {
                adjacencyMatrix[i][j] = 0;
            } else {
                cout << namaSimpul[i] << " --> " << namaSimpul[j] << " = ";
                cin >> adjacencyMatrix[i][j];
            }
        }
    }
    cout << "\nAdjacency Matrix:\n";
    cout << setw(10) << " ";
    for (const auto &nama : namaSimpul) {
        cout << setw(10) << nama;
    }
    cout << endl;

    for (int i = 0; i < jumlahSimpul; i++) {
        cout << setw(10) << namaSimpul[i];
        for (int j = 0; j < jumlahSimpul; j++) {
            cout << setw(10) << adjacencyMatrix[i][j];
        }
        cout << endl;
    }
    return 0;
}
