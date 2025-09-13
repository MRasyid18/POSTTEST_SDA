#include <iostream>
using namespace std;

//NIM GENAP 2409106042

void tukar(int &x, int &y) {
    int sementara = x;
    x = y;
    y = sementara;
}

int main() {
    int a, b;

    cout << "Masukkan bilangan pertama : ";
    cin >> a;
    cout << "Masukkan bilangan kedua : ";
    cin >> b;
    cout << "Sebelum ditukar: a = " << a << ", b = " << b << endl;
    tukar(a, b);
    cout << "Sesudah ditukar: a = " << a << ", b = " << b << endl;

    return 0;
}