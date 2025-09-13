#include <iostream>
using namespace std;

//SOAL GENAP 2409106042
int main() {
    // matriks 3x3
    int matriks[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int jumlah = 0;

    // print matriks
    cout << "Matriks 3x3:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matriks[i][j] << " ";
        }
        cout << endl;
    }
    // untuk mengihtung jumlah elemen pada baris genap (baris 0 dan 2)
    for (int i = 0; i < 3; i++) {
        if (i % 2 == 0) { // baris genap
            for (int j = 0; j < 3; j++) {
                jumlah += matriks[i][j];
            }
        }
    }
    // print hasil
    cout << "Jumlah elemen pada baris genap \n1 + 2 + 3 + 7 + 8 + 9 = " << jumlah << endl;

    return 0;
}
