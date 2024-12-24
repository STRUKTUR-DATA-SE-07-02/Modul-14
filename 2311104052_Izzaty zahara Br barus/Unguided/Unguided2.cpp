#include <iostream>
#include <vector>

using namespace std;

void printAdjacencyMatrix(const vector<vector<int>>& matrix) {
    cout << "Adjacency Matrix:" << endl;
    for (const auto& row : matrix) {
        for (const auto& val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    int numNodes, numEdges;


    cout << "Masukkan jumlah simpul: ";
    cin >> numNodes;
    cout << "Masukkan jumlah sisi: ";
    cin >> numEdges;

    
    vector<vector<int>> adjacencyMatrix(numNodes, vector<int>(numNodes, 0));

    cout << "Masukkan pasangan simpul yang terhubung:" << endl;

    for (int i = 0; i < numEdges; ++i) {
        int node1, node2;
        cin >> node1 >> node2;

      
        node1--;
        node2--;

        adjacencyMatrix[node1][node2] = 1;
        adjacencyMatrix[node2][node1] = 1; 
    }

    printAdjacencyMatrix(adjacencyMatrix);

    return 0;
}
