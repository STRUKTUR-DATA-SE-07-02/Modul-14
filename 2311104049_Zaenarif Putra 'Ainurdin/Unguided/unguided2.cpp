#include <iostream>
#include <vector>
#include <iomanip>
#include <sstream>

using namespace std;

int main() {
    int jumlahSimpul, jumlahSisi;

    cout << "Masukkan jumlah simpul: ";
    cin >> jumlahSimpul;

    cout << "Masukkan jumlah sisi: ";
    cin >> jumlahSisi;

    vector<vector<int>> matriks(jumlahSimpul, vector<int>(jumlahSimpul, 0));

    cout << "Masukkan pasangan simpul (misal: 1 2):\n";
    cin.ignore();
    for (int i = 0; i < jumlahSisi; i++) {
        string input;
        getline(cin, input);

        istringstream iss(input);
        int u, v;
        iss >> u >> v;

        u--; 
        v--;

        matriks[u][v] = 1;
        matriks[v][u] = 1;
    }

    cout << "\nAdjacency Matrix:\n";
    for (int i = 0; i < jumlahSimpul; i++) {
        for (int j = 0; j < jumlahSimpul; j++) {
            cout << matriks[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}