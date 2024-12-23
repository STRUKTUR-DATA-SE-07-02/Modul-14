#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Graph {
private:
    int vertices;
    vector<vector<int>> adjacencyMatrix;
    vector<string> cityNames;

public:
    // Constructor
    Graph(int v) {
        vertices = v;
        adjacencyMatrix.resize(v, vector<int>(v, 0));
        cityNames.resize(v);
    }

    // Menambahkan nama kota
    void addCityName(int index, string name) {
        cityNames[index] = name;
    }

    // Menambahkan edge dengan bobot
    void addEdge(int from, int to, int weight) {
        adjacencyMatrix[from][to] = weight;
    }

    // Menampilkan matrix adjacency
    void displayMatrix() {
        // Menampilkan header kolom
        cout << "\n\t";
        for(int i = 0; i < vertices; i++) {
            cout << cityNames[i] << "\t";
        }
        cout << endl;

        // Menampilkan matrix
        for(int i = 0; i < vertices; i++) {
            cout << cityNames[i] << "\t";
            for(int j = 0; j < vertices; j++) {
                cout << adjacencyMatrix[i][j] << "\t";
            }
            cout << endl;
        }
    }

    // Getter untuk nama kota
    string getCityName(int index) {
        return cityNames[index];
    }
};

int main() {
    int numVertices;
    
    cout << "Silakan masukan jumlah simpul : ";
    cin >> numVertices;

    Graph graph(numVertices);
    
    cout << "Silakan masukan nama simpul" << endl;
    for(int i = 0; i < numVertices; i++) {
        string cityName;
        cout << "Simpul " << i + 1 << " : ";
        cin >> cityName;
        graph.addCityName(i, cityName);
    }

    cout << "Silakan masukkan bobot antar simpul" << endl;
    for(int i = 0; i < numVertices; i++) {
        for(int j = 0; j < numVertices; j++) {
            if(i != j) {
                int weight;
                string fromCity = graph.getCityName(i);
                string toCity = graph.getCityName(j);
                cout << fromCity << "---> " << toCity << " = ";
                cin >> weight;
                graph.addEdge(i, j, weight);
            }
        }
    }

    // Menampilkan hasil matrix adjacency
    graph.displayMatrix();

    return 0;
}