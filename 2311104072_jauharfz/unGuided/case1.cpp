#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

class Graph
{
private:
  int V; // jumlah vertex/kota
  vector<vector<int>> adjMatrix;
  vector<string> cityNames;

public:
  // Constructor
  Graph(int vertices)
  {
    V = vertices;
    // Membuat matrix berukuran V x V dan diisi dengan 0
    adjMatrix.resize(V, vector<int>(V, 0));
    // Membuat array untuk nama kota dengan ukuran V
    cityNames.resize(V);
  }

  // Fungsi untuk menambahkan nama kota ke array cityNames
  void addCityName(int index, string name)
  {
    cityNames[index] = name;
  }

  // Fungsi untuk menambahkan bobot antara dua kota
  void addEdge(int source, int dest, int weight)
  {
    adjMatrix[source][dest] = weight;
  }

  // Fungsi untuk mendapatkan nama kota berdasarkan index
  string getCityName(int index)
  {
    return cityNames[index];
  }

  // Fungsi untuk menampilkan matrix adjacency
  void printMatrix()
  {
    // Mencetak header (nama-nama kota sebagai kolom)
    cout << "\n      ";
    for (int i = 0; i < V; i++)
    {
      cout << left << setw(8) << cityNames[i];
    }
    cout << "\n";

    // Mencetak matrix dengan nama kota di sebelah kiri
    for (int i = 0; i < V; i++)
    {
      cout << left << setw(6) << cityNames[i]; // Nama kota di kiri
      for (int j = 0; j < V; j++)
      {
        cout << left << setw(8) << adjMatrix[i][j]; // Bobot antar kota
      }
      cout << "\n";
    }
  }
};

int main()
{
  int V;
  cout << "Silakan masukan jumlah simpul: ";
  cin >> V; // Input jumlah kota

  Graph g(V); // Membuat objek Graph dengan V vertex

  // Input nama untuk setiap kota
  cout << "Silakan masukan nama simpul\n";
  cin.ignore(); // Membersihkan buffer input
  for (int i = 0; i < V; i++)
  {
    string cityName;
    cout << "Simpul " << i + 1 << " : ";
    getline(cin, cityName);
    g.addCityName(i, cityName);
  }

  // Input bobot/jarak antar kota
  cout << "\nSilakan masukkan bobot antar simpul\n";
  for (int i = 0; i < V; i++)
  {
    for (int j = 0; j < V; j++)
    {
      if (i != j) // Tidak perlu input bobot ke kota yang sama
      {
        int weight;
        cout << g.getCityName(i) << "--> " << g.getCityName(j) << " = ";
        cin >> weight;
        g.addEdge(i, j, weight);
      }
    }
  }

  // Menampilkan hasil dalam bentuk matrix
  g.printMatrix();

  return 0;
}
