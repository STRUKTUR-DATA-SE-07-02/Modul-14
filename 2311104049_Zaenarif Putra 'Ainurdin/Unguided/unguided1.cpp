#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>

using namespace std;

int main() {
    int jumlahSimpul;

    cout << "Silakan masukan jumlah simpul (minimal 1): ";
    while (true) {
        cin >> jumlahSimpul;
        if (cin.fail() || jumlahSimpul < 1) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input tidak valid. Silakan masukkan angka positif: ";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }

    vector<string> simpul(jumlahSimpul);

    for (int i = 0; i < jumlahSimpul; i++) {
        cout << "Simpul " << i + 1 << ": ";
        cin >> simpul[i];
    }

    vector<vector<int>> matriks(jumlahSimpul, vector<int>(jumlahSimpul, 0));

    for (int i = 0; i < jumlahSimpul; i++) {
        for (int j = 0; j < jumlahSimpul; j++) {
            cout << simpul[i] << " --> " << simpul[j] << " = ";
            while (true) {
                cin >> matriks[i][j];
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Input tidak valid. Silakan masukkan angka: ";
                } else {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
            }
        }
    }

    cout << "\nMatriks Bobot:\n";
    cout << setw(8) << " ";
    for (const auto& s : simpul) {
        cout << setw(8) << s;
    }
    cout << endl;

    for (int i = 0; i < jumlahSimpul; i++) {
        cout << setw(8) << simpul[i];
        for (int j = 0; j < jumlahSimpul; j++) {
            cout << setw(8) << matriks[i][j];
        }
        cout << endl;
    }

    return 0;
}