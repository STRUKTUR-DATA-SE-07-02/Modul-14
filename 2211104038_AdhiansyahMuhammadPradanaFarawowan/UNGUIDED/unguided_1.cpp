#include <iostream>
#include <string>
#include <vector>
#include <map>

struct Vertex
{
    std::string name;
    std::map<std::string, int> weighted_edges;
};

struct Graph
{
    // Vektor pada dasarnya adalah array yang dapat berubah ukuran
    // Vektor tanpa menetapkan ukuran awal akan mulai dari ukuran 0 (nol)
    std::vector<Vertex> vertices;
};

int main()
{
    int n;
    Graph cities;

    std::string input_n;

    std::cout << "Masukkan jumlah simpul yang ingin dibuat: ";
    std::cin >> n;

    std::cout << "Masukkan nama simpul:\n";

    while (cities.vertices.size() != n)
    {
        std::cout << "Simpul " << cities.vertices.size() + 1 << ": ";
        std::cin >> input_n;

        Vertex v;
        v.name = input_n;

        cities.vertices.push_back(v);
    }

    std::cout << "Masukkan jarak kota: " << '\n';

    int distance;
    for (int i = 0; i < n; i = i + 1)
    {
        for (int j = 0; j < n; j = j + 1)
        {
            if (i != j)
            {
                std::cout << cities.vertices[i].name << " ---> " << cities.vertices[j].name << ": ";
                std::cin >> distance;

                cities.vertices[i].weighted_edges[cities.vertices[j].name] = distance;
            }
        }
    }

    std::cout << '\n';

    std::cout << "Matriks tetangga:\n";
    std::cout << "   ";
    for (int _i = 0; _i < n; _i = _i + 1)
    {
        std::cout << "(" << _i + 1 << ")" << " ";
    }

    std::cout << '\n';

    for (int i = 0; i < n; i = i + 1)
    {
        std::cout << "(" << i + 1 << ")" << " ";
        for (int j = 0; j < n; j = j + 1)
        {
            std::cout << cities.vertices[i].weighted_edges[cities.vertices[j].name] << " ";
        }

        std::cout << '\n';
    }

    return 0;
}
