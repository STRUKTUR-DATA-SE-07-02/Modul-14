#include <iostream>
using namespace std;

const int MAX_VERTICES = 10;

class Graph {
private:
    int vertices;
    int matrix[MAX_VERTICES][MAX_VERTICES];

public:
    Graph(int v) {
        vertices = v;
        for(int i = 0; i < vertices; i++) {
            for(int j = 0; j < vertices; j++) {
                matrix[i][j] = 0;
            }
        }
    }

    void addEdge(int v1, int v2) {
        matrix[v1-1][v2-1] = 1;
        matrix[v2-1][v1-1] = 1;
    }

    void printMatrix() {
        cout << "\nAdjacency Matrix:" << endl;
        for(int i = 0; i < vertices; i++) {
            for(int j = 0; j < vertices; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int vertices, edges;

    cout << "Masukkan jumlah simpul: ";
    cin >> vertices;

    cout << "Masukkan jumlah sisi: ";
    cin >> edges;

    Graph graph(vertices);

    cout << "\nMasukkan pasangan simpul:\n";
    for(int i = 0; i < edges; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        graph.addEdge(v1, v2);
    }

    graph.printMatrix();

    return 0;
}
