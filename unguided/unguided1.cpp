#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    int jumlahSimpul;
    cout << "Silakan masukan jumlah simpul: ";
    cin >> jumlahSimpul;

    vector<string> namaSimpul(jumlahSimpul);
    for (int i = 0; i < jumlahSimpul; i++) {
        cout << "Simpul " << i + 1 << " : ";
        cin >> namaSimpul[i];
    }

    // Membuat adjacency matrix
    vector<vector<int>> graph(jumlahSimpul, vector<int>(jumlahSimpul, 0));
    cout << "\nSilakan masukkan bobot antar simpul\n";
    for (int i = 0; i < jumlahSimpul; i++) {
        for (int j = 0; j < jumlahSimpul; j++) {
            if (i == j) {
                graph[i][j] = 0; // Bobot dari simpul ke dirinya sendiri 0
            } else {
                cout << namaSimpul[i] << "--> " << namaSimpul[j] << " = ";
                cin >> graph[i][j];
            }
        }
    }

    // Menampilkan adjacency matrix
    cout << "\nAdjacency Matrix:\n";
    cout << setw(10) << " ";
    for (const string& nama : namaSimpul) {
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
