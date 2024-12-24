#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;

    // Input jumlah simpul dan sisi
    cout << "Masukkan jumlah simpul: ";
    cin >> n;
    cout << "Masukkan jumlah sisi: ";
    cin >> m;

    // Inisialisasi adjacency matrix dengan nilai 0
    vector<vector<int>> adj(n, vector<int>(n, 0));

    // Input pasangan simpul yang terhubung
    cout << "Masukkan pasangan simpul:\n";
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        // Kurangi 1 karena indeks array dimulai dari 0
        u--;
        v--;
        adj[u][v] = 1;
        adj[v][u] = 1; // Karena graf tidak berarah
    }

    // Tampilkan adjacency matrix
    cout << "Adjacency Matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << adj[i][j];
        }
        cout << endl;
    }

    return 0;
}
