#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int numVertices, numEdges;

    // Input jumlah simpul dan jumlah sisi
    cout << "Masukkan jumlah simpul: ";
    cin >> numVertices;
    cout << "Masukkan jumlah sisi: ";
    cin >> numEdges;

    // Deklarasi adjacency matrix
    vector<vector<int>> adjacencyMatrix(numVertices, vector<int>(numVertices, 0));
    vector<string> vertexLabels(numVertices);

    // Input label simpul
    cout << "Masukkan nama simpul:\n";
    for (int i = 0; i < numVertices; ++i) {
        cout << "Simpul " << i + 1 << ": ";
        cin >> vertexLabels[i];
    }

    // Input sisi antar simpul
    cout << "\nMasukkan pasangan simpul yang terhubung:\n";
    for (int i = 0; i < numEdges; ++i) {
        string from, to;
        cout << "Sisi " << i + 1 << ": ";
        cin >> from >> to;

        int fromIdx = -1, toIdx = -1;
        for (int j = 0; j < numVertices; ++j) {
            if (vertexLabels[j] == from) fromIdx = j;
            if (vertexLabels[j] == to) toIdx = j;
        }

        if (fromIdx != -1 && toIdx != -1) {
            adjacencyMatrix[fromIdx][toIdx] = 1;
            adjacencyMatrix[toIdx][fromIdx] = 1; // Untuk graf tak berarah
        } else {
            cout << "Nama simpul tidak valid. Coba lagi.\n";
            --i;
        }
    }

    // Menampilkan adjacency matrix
    cout << "\nAdjacency Matrix:\n";
    cout << " ";
    for (const auto& label : vertexLabels) {
        cout << "\t" << label;
    }
    cout << "\n";

    for (int i = 0; i < numVertices; ++i) {
        cout << vertexLabels[i];
        for (int j = 0; j < numVertices; ++j) {
            cout << "\t" << adjacencyMatrix[i][j];
        }
        cout << "\n";
    }

    return 0;
}
