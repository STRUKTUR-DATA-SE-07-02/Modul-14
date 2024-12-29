#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    int jumlahSimpul;

    cout << "Silakan masukkan jumlah simpul: ";
    cin >> jumlahSimpul;
    cin.ignore();

    vector<string> simpul(jumlahSimpul);

    for (int i = 0; i < jumlahSimpul; i++) {
        cout << "Silakan masukkan nama simpul" << endl;
        cout << "Simpul " << i + 1 << ": ";
        getline(cin, simpul[i]);
    }

    vector<vector<int>> bobot(jumlahSimpul, vector<int>(jumlahSimpul));

    for (int i = 0; i < jumlahSimpul; i++) {
        for (int j = 0; j < jumlahSimpul; j++) {
            if (i == j) {
                bobot[i][j] = 0;
            } else {
                cout << simpul[i] << "--> " << simpul[j] << " = ";
                cin >> bobot[i][j];
            }
        }
    }

    cout << "\n\t";
    for (const string& namaSimpul : simpul) {
        cout << setw(8) << namaSimpul;
    }
    cout << endl;

    for (int i = 0; i < jumlahSimpul; i++) {
        cout << setw(8) << simpul[i];
        for (int j = 0; j < jumlahSimpul; j++) {
            cout << setw(8) << bobot[i][j];
        }
        cout << endl;
    }

    return 0;
}
