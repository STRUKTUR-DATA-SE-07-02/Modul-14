#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int main() {
    int n;
    cout << "Silakan masukan jumlah simpul: ";
    cin >> n;

    vector<string> kota(n);
    cout << "Silakan masukan nama simpul:\n";
    for (int i = 0; i < n; i++) {
        cout << "Simpul " << i + 1 << ": ";
        cin >> kota[i];
    }

    vector<vector<int>> jarak(n, vector<int>(n, INT_MAX));
    cout << "Silakan masukan bobot antar simpul:\n";
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cout << kota[i] << " --> " << kota[j] << ": ";
            int bobot;
            cin >> bobot;
            jarak[i][j] = bobot;
            jarak[j][i] = bobot;
        }
    }

    cout << "\nAdjacency Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (jarak[i][j] == INT_MAX)
                cout << "0 ";
            else
                cout << jarak[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
