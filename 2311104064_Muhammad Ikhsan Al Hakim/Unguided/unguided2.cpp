#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cout << "Masukkan jumlah simpul: ";
    cin >> n;
    cout << "Masukkan jumlah sisi: ";
    cin >> m;

    vector<vector<int>> adjacencyMatrix(n, vector<int>(n, 0));

    cout << "Masukkan pasangan simpul yang terhubung:" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjacencyMatrix[u - 1][v - 1] = 1; 
        adjacencyMatrix[v - 1][u - 1] = 1; 
    }

    cout << "Adjacency Matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adjacencyMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}