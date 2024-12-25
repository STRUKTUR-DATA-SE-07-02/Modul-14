#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // Untuk format output tabel

using namespace std;

int main() {
    int nodes;
    cout << "Silakan masukkan jumlah simpul: ";
    cin >> nodes;

    // Menyimpan nama simpul
    vector<string> nodeNames(nodes);
    for (int i = 0; i < nodes; i++) {
        cout << "Simpul " << i + 1 << ": ";
        cin >> nodeNames[i];
    }

    // Membuat adjacency matrix
    vector<vector<int>> adjMatrix(nodes, vector<int>(nodes, 0));

    // Memasukkan bobot antar simpul
    cout << "Silakan masukkan bobot antar simpul" << endl;
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            cout << nodeNames[i] << "--> " << nodeNames[j] << " = ";
            cin >> adjMatrix[i][j];
        }
    }

    // Menampilkan adjacency matrix
    cout << endl;
    cout << setw(10) << " ";
    for (const auto &name : nodeNames) {
        cout << setw(10) << name;
    }
    cout << endl;

    for (int i = 0; i < nodes; i++) {
        cout << setw(10) << nodeNames[i];
        for (int j = 0; j < nodes; j++) {
            cout << setw(10) << adjMatrix[i][j];
        }
        cout << endl;
    }

    return 0;
}
