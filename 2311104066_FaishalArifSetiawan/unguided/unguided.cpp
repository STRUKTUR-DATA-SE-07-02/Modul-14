#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cout << "Silakan masukkan jumlah simpul: ";
    cin >> n;

    vector<string> kota(n);
    vector<vector<int>> graph(n, vector<int>(n, 0));

    // Input nama-nama kota
    for (int i = 0; i < n; i++) {
        cout << "Simpul " << i + 1 << ": ";
        cin >> ws; 
        getline(cin, kota[i]);
    }

    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                cout << kota[i] << " --> " << kota[j] << ": ";
                cin >> graph[i][j];
            }
        }
    }

    
    cout << "\nMatriks Bobot:\n";
    cout << setw(10) << " ";
    for (const auto& k : kota) {
        cout << setw(10) << k;
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << setw(10) << kota[i];
        for (int j = 0; j < n; j++) {
            cout << setw(10) << graph[i][j];
        }
        cout << endl;
    }

    return 0;
}
