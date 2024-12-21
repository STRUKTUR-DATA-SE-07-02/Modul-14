#include <iostream>
#include <vector>
using namespace std;

void printMatrix(const vector<vector<int>> &matrix)
{
    for (const auto &row : matrix)
    {
        for (const auto &val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main()
{
    int numVertices, numEdges;

    // Input jumlah simpul dan sisi
    cout << "Masukkan jumlah simpul: ";
    cin >> numVertices;
    cout << "Masukkan jumlah sisi: ";
    cin >> numEdges;

    // Inisialisasi adjacency matrix
    vector<vector<int>> adjMatrix(numVertices, vector<int>(numVertices, 0));

    // Input pasangan simpul
    cout << "Masukkan pasangan simpul:" << endl;
    for (int i = 0; i < numEdges; i++)
    {
        int u, v;
        cin >> u >> v;

        // Simpul diubah menjadi indeks (0-based)
        u--;
        v--;

        // Tandai sisi dalam adjacency matrix
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // Karena graf tidak berarah
    }

    // Output adjacency matrix
    cout << "Adjacency Matrix:" << endl;
    printMatrix(adjMatrix);

    return 0;
}
