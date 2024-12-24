#include <iostream>
#include <string>
#include <iomanip>
#define MAX 100
using namespace std;

int main() {
    int jumlahSimpul;
    string namaSimpul[MAX];
    int bobot[MAX][MAX];
    
    // Input jumlah simpul
    cout << "Silakan masukan jumlah simpul : ";
    cin >> jumlahSimpul;
    
    // Input nama simpul
    for(int i = 0; i < jumlahSimpul; i++) {
        cout << "Simpul " << i+1 << " : ";
        cin >> namaSimpul[i];
    }
    
    // Inisialisasi matriks bobot dengan 0
    for(int i = 0; i < jumlahSimpul; i++) {
        for(int j = 0; j < jumlahSimpul; j++) {
            bobot[i][j] = 0;
        }
    }
    
    // Input bobot antar simpul
    cout << "Silakan masukkan bobot antar simpul\n";
    
    // Input untuk BALI ke BALI
    cout << namaSimpul[0] << "--> " << namaSimpul[0] << " = ";
    cin >> bobot[0][0];
    
    // Input untuk BALI ke PALU
    cout << namaSimpul[0] << "--> " << namaSimpul[1] << " = ";
    cin >> bobot[0][1];
    
    // Input untuk PALU ke BALI
    cout << namaSimpul[1] << "--> " << namaSimpul[0] << " = ";
    cin >> bobot[1][0];
    
    // Input untuk PALU ke PALU
    cout << namaSimpul[1] << "--> " << namaSimpul[1] << " = ";
    cin >> bobot[1][1];
    
    // Menampilkan matriks bobot
    cout << "\n";
    cout << setw(10) << " ";
    for(int i = 0; i < jumlahSimpul; i++) {
        cout << setw(10) << namaSimpul[i];
    }
    cout << "\n";
    
    for(int i = 0; i < jumlahSimpul; i++) {
        cout << setw(10) << namaSimpul[i];
        for(int j = 0; j < jumlahSimpul; j++) {
            cout << setw(10) << bobot[i][j];
        }
        cout << "\n";
    }
    
    return 0;
}