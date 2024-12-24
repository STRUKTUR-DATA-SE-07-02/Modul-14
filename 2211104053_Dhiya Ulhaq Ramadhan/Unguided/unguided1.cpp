#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>

class Graph {
private:
    std::vector<std::string> cities;
    std::map<std::string, std::map<std::string, int>> distances;

public:
    void addCity(const std::string& city) {
        cities.push_back(city);
        distances[city] = std::map<std::string, int>();
        for (const auto& existingCity : cities) {
            distances[city][existingCity] = 0;
            distances[existingCity][city] = 0;
        }
    }

    void addDistance(const std::string& from, const std::string& to, int distance) {
        distances[from][to] = distance;
        distances[to][from] = distance;
    }

    void displayMatrix() const {
        std::cout << std::setw(8) << "";
        for (const auto& city : cities) {
            std::cout << std::setw(8) << city;
        }
        std::cout << "\n";

        for (const auto& fromCity : cities) {
            std::cout << std::setw(8) << fromCity;
            for (const auto& toCity : cities) {
                std::cout << std::setw(8) << distances.at(fromCity).at(toCity);
            }
            std::cout << "\n";
        }
    }

    const std::vector<std::string>& getCities() const {
        return cities;
    }
};

std::string toUpper(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}
int main() {
    Graph graph;
    int numCities;

    std::cout << "Silakan masukan jumlah simpul: ";
    std::cin >> numCities;
    std::cin.ignore();

    for (int i = 1; i <= numCities; i++) {
        std::string cityName;
        std::cout << "Simpul " << i << ": ";
        std::getline(std::cin, cityName);
        graph.addCity(toUpper(cityName));
    }

    std::cout << "\nSilakan masukkan bobot antar simpul:\n";
    const auto& cities = graph.getCities();
    for (size_t i = 0; i < cities.size(); i++) {
        for (size_t j = i + 1; j < cities.size(); j++) {
            int distance;
            std::cout << cities[i] << " -> " << cities[j] << " = ";
            std::cin >> distance;
            graph.addDistance(cities[i], cities[j], distance);
        }
    }

    std::cout << "\nMatriks Jarak:\n";
    graph.displayMatrix();

    return 0;
}
