#include <iostream>
#include <string>
#include <iomanip>
#define MAX_VERTICES 100
using namespace std;

int main() {
    int totalVertices;
    string vertexNames[MAX_VERTICES];
    int weightMatrix[MAX_VERTICES][MAX_VERTICES];

    // Memasukkan jumlah simpul
    cout << "Masukkan jumlah simpul: ";
    cin >> totalVertices;

    // Memasukkan nama-nama simpul
    for (int idx = 0; idx < totalVertices; ++idx) {
        cout << "Nama simpul " << idx + 1 << ": ";
        cin >> vertexNames[idx];
    }

    // Memasukkan bobot antar simpul dengan tabel
    cout << "\nMasukkan bobot antar simpul dalam bentuk matriks:\n";
    for (int row = 0; row < totalVertices; ++row) {
        for (int col = 0; col < totalVertices; ++col) {
            cout << "Bobot " << vertexNames[row] << " ke " << vertexNames[col] << ": ";
            cin >> weightMatrix[row][col];
        }
    }

    // Menampilkan matriks bobot
    cout << "\nMatriks Bobot:\n";
    cout << setw(10) << " ";
    for (int col = 0; col < totalVertices; ++col) {
        cout << setw(10) << vertexNames[col];
    }
    cout << "\n";

    for (int row = 0; row < totalVertices; ++row) {
        cout << setw(10) << vertexNames[row];
        for (int col = 0; col < totalVertices; ++col) {
            cout << setw(10) << weightMatrix[row][col];
        }
        cout << "\n";
    }

    return 0;
}
