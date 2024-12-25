#include <iostream>
#include <vector>
using namespace std;

class Graph
{
private:
  int V; // jumlah vertex/simpul
  vector<vector<int>> adjMatrix;

public:
  // Constructor
  Graph(int vertices)
  {
    V = vertices;
    // Inisialisasi matrix dengan ukuran V x V dengan nilai 0
    adjMatrix.resize(V, vector<int>(V, 0));
  }

  // Menambahkan edge untuk graf tidak berarah
  void addEdge(int v1, int v2)
  {
    // Karena graf tidak berarah, kedua arah diberi nilai 1
    adjMatrix[v1 - 1][v2 - 1] = 1;
    adjMatrix[v2 - 1][v1 - 1] = 1;
  }

  // Menampilkan adjacency matrix
  void printMatrix()
  {
    cout << "\nAdjacency Matrix:" << endl;
    for (int i = 0; i < V; i++)
    {
      for (int j = 0; j < V; j++)
      {
        cout << adjMatrix[i][j] << " ";
      }
      cout << endl;
    }
  }
};

int main()
{
  int V, E;

  cout << "Masukkan jumlah simpul: ";
  cin >> V;

  cout << "Masukkan jumlah sisi: ";
  cin >> E;

  Graph g(V);

  cout << "Masukkan pasangan simpul:" << endl;
  for (int i = 0; i < E; i++)
  {
    int v1, v2;
    cin >> v1 >> v2;
    g.addEdge(v1, v2);
  }

  g.printMatrix();

  return 0;
}
