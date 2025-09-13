#include <iostream>
using namespace std;

//NIM GENAP 2409106042

struct Mahasiswa
{
    string nama;
    string nim;
    float ipk;
};

int main() {
    Mahasiswa mhs[4];
    int jumlah = 4;

    cout << "Masukkan data mahasiswa (max 4 data dan tanpa spasi)" << endl;
    for (int i = 0; i < jumlah; i++) {
        cout << "Mahasiswa ke- " << i+1 << endl;
        cout << "Nama : ";
        cin >> mhs[i].nama;
        cout << "NIM : ";
        cin >> mhs[i].nim;
        cout << "IPK : ";
        cin >> mhs[i].ipk;
        cout << endl;
    }

    for (int i = 0; i < jumlah-1; i++) {
        for (int j = 0; j < jumlah-1-i; j++) {
            if (mhs[j].ipk > mhs[j+1].ipk) {
                Mahasiswa temp = mhs[j];
                mhs[j] = mhs[j+1];
                mhs[j+1] = temp;
            }
        }
    }
    cout << "\nData mahasiswa diurutkan berdasarkan IPK ascending : " << endl;
    for (int i = 0; i < jumlah; i++) {
        cout << mhs[i].nama << " | " << mhs[i].nim << " | " << mhs[i].ipk << endl;
    }
    return 0;
}