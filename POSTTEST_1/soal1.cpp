#include <iostream>
using namespace std;

//SOAL GENAP 2409106042
void balikArray(int* arr, int size) {
    int* awal = arr;
    int* akhir = arr + size - 1;

    while (awal < akhir) {
        int temp = *awal;
        *awal = *akhir;
        *akhir = temp;
        awal++;
        akhir--;
    }
}

int main() {
    int bilanganPrima[7] = {2, 3, 5, 7, 11, 13, 17};
    int ukuran = 7;

    cout << "Array sebelum dibalik: ";
    for (int i = 0; i < ukuran; i++) {
        cout << bilanganPrima[i] << " ";
    }
    cout << endl;

    cout << "Array sesudah dibalik: ";
    balikArray(bilanganPrima, ukuran);
    for (int i = 0; i < ukuran; i++) {
        cout << bilanganPrima[i] << " ";
    }
    cout << endl;

    return 0;
}