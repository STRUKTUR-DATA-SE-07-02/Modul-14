#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    vector<vector<int>> adjacencyMatrix;
    int vertices;

public:
    // Constructor untuk inisialisasi matrix dengan ukuran vertices x vertices
    Graph(int v) : vertices(v) {
        adjacencyMatrix.resize(v, vector<int>(v, 0));
    }

    // Fungsi untuk menambahkan edge antara dua vertex
    void addEdge(int v1, int v2) {
        // Karena graf tidak berarah, set kedua arah dengan nilai 1
        adjacencyMatrix[v1-1][v2-1] = 1;
        adjacencyMatrix[v2-1][v1-1] = 1;
    }

    // Fungsi untuk menampilkan adjacency matrix
    void displayMatrix() {
        cout << "\nAdjacency Matrix:\n";
        for(int i = 0; i < vertices; i++) {
            for(int j = 0; j < vertices; j++) {
                cout << adjacencyMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int numVertices, numEdges;

    cout << "Masukkan jumlah simpul: ";
    cin >> numVertices;

    cout << "Masukkan jumlah sisi: ";
    cin >> numEdges;

    Graph graph(numVertices);

    cout << "Masukkan pasangan simpul:\n";
    for(int i = 0; i < numEdges; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        graph.addEdge(v1, v2);
    }

    graph.displayMatrix();

    return 0;
}
