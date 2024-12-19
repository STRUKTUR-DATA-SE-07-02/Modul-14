#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int MAX = 10;

class Graph {
private:
    int numVertices;
    string vertices[MAX];
    int adjMatrix[MAX][MAX];

public:
    Graph() {
        numVertices = 0;
        for(int i = 0; i < MAX; i++) {
            for(int j = 0; j < MAX; j++) {
                adjMatrix[i][j] = 0;
            }
        }
    }

    void addVertex(string name) {
        if(numVertices < MAX) {
            vertices[numVertices] = name;
            numVertices++;
        }
    }

    void addEdge(int start, int end, int weight) {
        adjMatrix[start][end] = weight;
    }

    void printMatrix() {
        cout << setw(10) << " ";
        for(int i = 0; i < numVertices; i++) {
            cout << setw(10) << vertices[i];
        }
        cout << endl;

        for(int i = 0; i < numVertices; i++) {
            cout << setw(10) << vertices[i];
            for(int j = 0; j < numVertices; j++) {
                cout << setw(10) << adjMatrix[i][j];
            }
            cout << endl;
        }
    }

    int getNumVertices() {
        return numVertices;
    }

    string getVertex(int index) {
        return vertices[index];
    }
};

int main() {
    Graph graph;
    int numVertices;
    string vertexName;

    cout << "Silakan masukan jumlah simpul : ";
    cin >> numVertices;

    cout << "Silakan masukan nama simpul" << endl;
    for(int i = 0; i < numVertices; i++) {
        cout << "Simpul " << i+1 << " : ";
        cin >> vertexName;
        graph.addVertex(vertexName);
    }

    cout << "Silakan masukkan bobot antar simpul" << endl;
    for(int i = 0; i < numVertices; i++) {
        for(int j = 0; j < numVertices; j++) {
            string start = graph.getVertex(i);
            string end = graph.getVertex(j);
            cout << start << "---> " << end << " = ";
            int weight;
            cin >> weight;
            graph.addEdge(i, j, weight);
        }
    }

    cout << endl;
    graph.printMatrix();

    return 0;
}
