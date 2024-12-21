#include <iostream>
#include <vector>
#include <iomanip> // Untuk format output
using namespace std;

int main()
{
    int numNodes;

    // Input jumlah simpul
    cout << "Silakan masukkan jumlah simpul: ";
    cin >> numNodes;

    // Input nama simpul
    vector<string> nodes(numNodes);
    for (int i = 0; i < numNodes; i++)
    {
        cout << "Simpul " << i + 1 << ": ";
        cin >> nodes[i];
    }

    // Membuat matriks bobot
    vector<vector<int>> graph(numNodes, vector<int>(numNodes, 0));

    // Input bobot antar simpul
    cout << "Silakan masukkan bobot antar simpul:\n";
    for (int i = 0; i < numNodes; i++)
    {
        for (int j = 0; j < numNodes; j++)
        {
            if (i == j)
            {
                graph[i][j] = 0; // Bobot ke diri sendiri adalah 0
            }
            else
            {
                cout << nodes[i] << " --> " << nodes[j] << " = ";
                cin >> graph[i][j];
            }
        }
    }

    // Menampilkan matriks adjacency
    cout << "\nAdjacency Matrix:\n";
    cout << setw(10) << ""; // Header kosong
    for (const auto &node : nodes)
    {
        cout << setw(10) << node;
    }
    cout << endl;

    for (int i = 0; i < numNodes; i++)
    {
        cout << setw(10) << nodes[i];
        for (int j = 0; j < numNodes; j++)
        {
            cout << setw(10) << graph[i][j];
        }
        cout << endl;
    }

    return 0;
}
