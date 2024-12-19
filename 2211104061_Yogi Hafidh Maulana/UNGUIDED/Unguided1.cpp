#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void printMatrix(const vector<vector<int>> &matrix, const vector<string> &nodes)
{
    int n = nodes.size();

    cout << setw(8) << "";
    for (int i = 0; i < n; i++)
    {
        cout << setw(8) << nodes[i];
    }
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout << setw(8) << nodes[i];
        for (int j = 0; j < n; j++)
        {
            cout << setw(8) << matrix[i][j];
        }
        cout << endl;
    }
}

int main()
{
    int numNodes;
    cout << "Silakan masukan jumlah simpul: ";
    cin >> numNodes;

    vector<string> nodes(numNodes);
    cout << "Silakan masukan nama simpul:\n";
    for (int i = 0; i < numNodes; i++)
    {
        cout << "Simpul " << i + 1 << ": ";
        cin >> nodes[i];
    }

    vector<vector<int>> weights(numNodes, vector<int>(numNodes, 0));

    cout << "Silakan masukkan bobot antar simpul:\n";
    for (int i = 0; i < numNodes; i++)
    {
        for (int j = 0; j < numNodes; j++)
        {
            if (i != j || (i == j && weights[i][j] == 0))
            {
                cout << nodes[i] << " --> " << nodes[j] << " = ";
                cin >> weights[i][j];
            }
        }
    }

    cout << "\n";
    printMatrix(weights, nodes);

    return 0;
}
