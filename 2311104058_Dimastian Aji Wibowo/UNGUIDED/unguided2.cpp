#include <iostream>
#include <vector>
using namespace std;

int main() {
    int jumlahSimpul, jumlahSisi;

    cout << "Masukkan jumlah simpul: ";
    cin >> jumlahSimpul;
    cout << "Masukkan jumlah sisi: ";
    cin >> jumlahSisi;

    vector<vector<int>> adjacencyMatrix(jumlahSimpul, vector<int>(jumlahSimpul, 0));

    cout << "Masukkan pasangan simpul:\n";
    for (int i = 0; i < jumlahSisi; i++) {
        int simpul1, simpul2;
        cin >> simpul1 >> simpul2;

        simpul1--;
        simpul2--;

        adjacencyMatrix[simpul1][simpul2] = 1;
        adjacencyMatrix[simpul2][simpul1] = 1; 
    }
    cout << "Adjacency Matrix:\n";
    for (const auto &row : adjacencyMatrix) {
        for (const auto &value : row) {
            cout << value << " ";
        }
        cout << endl;
    }
    return 0;
}
