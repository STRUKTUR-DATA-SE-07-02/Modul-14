#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int jumlah_simpul;
    cout << "Silakan masukkan jumlah simpul: ";
    cin >> jumlah_simpul;

    vector<string> simpul(jumlah_simpul);
    for (int i = 0; i < jumlah_simpul; i++) {
        cout << "Simpul " << i + 1 << " : ";
        cin >> simpul[i];
    }

    vector<vector<int>> bobot(jumlah_simpul, vector<int>(jumlah_simpul, 0));

    cout << "Silakan masukkan bobot antar simpul" << endl;
    for (int i = 0; i < jumlah_simpul; i++) {
        for (int j = 0; j < jumlah_simpul; j++) {
            cout << simpul[i] << " --> " << simpul[j] << " = ";
            cin >> bobot[i][j];
        }
    }

    cout << endl;
    cout << setw(10) << " ";
    for (const auto& s : simpul) {
        cout << setw(10) << s;
    }
    cout << endl;

    for (int i = 0; i < jumlah_simpul; i++) {
        cout << setw(10) << simpul[i];
        for (int j = 0; j < jumlah_simpul; j++) {
            cout << setw(10) << bobot[i][j];
        }
        cout << endl;
    }

    return 0;
}
