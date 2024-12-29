#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

void displayMatrix(const vector<vector<int>>& graph, const vector<string>& cities) {
    int n = graph.size();
    cout << "\nAdjacency Matrix:\n";
    cout << "     ";
    for (const string& city : cities) {
        cout << city << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << cities[i] << " ";
        for (int j = 0; j < n; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Masukkan jumlah simpul: ";
    cin >> n;

    vector<string> cities(n);
    cout << "Masukkan nama simpul:\n";
    for (int i = 0; i < n; i++) {
        cout << "Simpul " << i + 1 << ": ";
        cin >> cities[i];
    }

    vector<vector<int>> graph(n, vector<int>(n, INT_MAX));

    cout << "\nMasukkan bobot antar simpul (jika tidak ada hubungan, masukkan 0):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                graph[i][j] = 0; // Jarak ke diri sendiri adalah 0
            } else {
                cout << cities[i] << " --> " << cities[j] << ": ";
                int weight;
                cin >> weight;
                graph[i][j] = (weight == 0) ? INT_MAX : weight;
            }
        }
    }

    displayMatrix(graph, cities);

    while (true) {
        cout << "\nHitung jarak dari kota ke kota (masukkan -1 untuk keluar):\n";
        string from, to;
        cout << "Dari: ";
        cin >> from;
        if (from == "-1") break;
        cout << "Ke: ";
        cin >> to;
        if (to == "-1") break;

        int fromIndex = -1, toIndex = -1;
        for (int i = 0; i < n; i++) {
            if (cities[i] == from) fromIndex = i;
            if (cities[i] == to) toIndex = i;
        }

        if (fromIndex == -1 || toIndex == -1) {
            cout << "Kota tidak ditemukan. Coba lagi.\n";
        } else if (graph[fromIndex][toIndex] == INT_MAX) {
            cout << "Tidak ada jalur langsung dari " << from << " ke " << to << ".\n";
        } else {
            cout << "Jarak dari " << from << " ke " << to << " adalah " << graph[fromIndex][toIndex] << ".\n";
        }
    }

    return 0;
}
