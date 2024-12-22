#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // Untuk format output

using namespace std;

int main() {
    int jumlahSimpul;

    // Meminta jumlah simpul dari user
    cout << "Silakan masukkan jumlah simpul: ";
    cin >> jumlahSimpul;

    vector<string> namaSimpul(jumlahSimpul);
    vector<vector<int>> graph(jumlahSimpul, vector<int>(jumlahSimpul, 0));

    // Input nama simpul
    for (int i = 0; i < jumlahSimpul; i++) {
        cout << "Silakan masukkan nama simpul " << i + 1 << ": ";
        cin >> namaSimpul[i];
    }

    // Input bobot antar simpul
    for (int i = 0; i < jumlahSimpul; i++) {
        for (int j = 0; j < jumlahSimpul; j++) {
            cout << namaSimpul[i] << "--> " << namaSimpul[j] << " = ";
            cin >> graph[i][j];
        }
    }

    // Output matriks adjacency
    cout << endl << setw(10) << "";
    for (const auto& nama : namaSimpul) {
        cout << setw(10) << nama;
    }
    cout << endl;

    for (int i = 0; i < jumlahSimpul; i++) {
        cout << setw(10) << namaSimpul[i];
        for (int j = 0; j < jumlahSimpul; j++) {
            cout << setw(10) << graph[i][j];
        }
        cout << endl;
    }

    return 0;
}
