#include <iostream>
#include <vector>
using namespace std;

void printAdjacencyMatrix(const vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int numNodes, numEdges;

    cout << "Masukkan jumlah simpul: ";
    cin >> numNodes;
    cout << "Masukkan jumlah sisi: ";
    cin >> numEdges;

    vector<vector<int>> adjacencyMatrix(numNodes, vector<int>(numNodes, 0));

    cout << "Masukkan pasangan simpul:\n";
    for (int i = 0; i < numEdges; i++)
    {
        int node1, node2;
        cin >> node1 >> node2;

        adjacencyMatrix[node1 - 1][node2 - 1] = 1;
        adjacencyMatrix[node2 - 1][node1 - 1] = 1;
    }

    cout << "\nAdjacency Matrix:\n";
    printAdjacencyMatrix(adjacencyMatrix);

    return 0;
}
