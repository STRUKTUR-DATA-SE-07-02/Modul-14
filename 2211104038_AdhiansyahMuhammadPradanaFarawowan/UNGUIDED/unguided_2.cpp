#include <iostream>
#include <string>
#include <vector>
#include <set>

struct Vertex
{
    std::string name;
    std::vector<std::string> edges_to_vertices;
};

struct Graph
{
    std::vector<Vertex> vertices;
};

// Pada dasarnya, kita buat grapf biasa
int main()
{
    Graph normal_graph;

    int n_vertices;
    int n_edges;

    std::cout << "Masukkan jumlah simpul: ";
    std::cin >> n_vertices;

    std::cout << "Masukkan jumlah sisi: ";
    std::cin >> n_edges;

    std::cout << "Isikan pasangan yang diinginkan (seperti: 1 2, simpul 1 ke simpul 2): " << '\n';

    std::string v1_name;
    std::string v2_name;
    for (int i = 0; i < n_edges; i = i + 1)
    {
        std::cin >> v1_name >> v2_name;

        Vertex v1;
        Vertex v2;
        v1.name = v1_name;
        v2.name = v2_name;

        for (int x = 0; x < normal_graph.vertices.size(); x = x + 1)
        {
            if (normal_graph.vertices[x].name == v1_name || normal_graph.vertices[x].name == v1_name)
            {
                normal_graph.vertices[x].edges_to_vertices.push_back(v2_name);
                break;
            }
        }

        normal_graph.vertices.push_back(v1);
        normal_graph.vertices.push_back(v2);
    }

    return 0;
}
