#include <iostream>
#include <string>
using namespace std;

//Muhammad Rasyid
//2409106042

struct penerbangan {
    string kode;
    string tujuan;
    string status;
};

struct Node {
    penerbangan data;
    Node* next;
};

Node* head = nullptr;
int counter = 1;

string buatKode() {
    if (counter == 1) {
        return "JT-042";
    } else {
        return "JT-042-" + to_string(counter - 1);
    }
}

bool isEmpty() {
    return head == nullptr;
}

void display(Node* head) {
    if (head == nullptr) {
        cout << "Tidak ada jadwal penerbangan" << endl;
        return;
    }
    
    cout << "\n--- Daftar Jadwal Penerbangan ---" << endl;
    Node* temp = head;
    int no = 1;
    
    while (temp != nullptr) {
        cout << "Jadwal " << no << ":" << endl;
        cout << "  Kode: " << temp->data.kode << endl;
        cout << "  Tujuan: " << temp->data.tujuan << endl;
        cout << "  Status: " << temp->data.status << endl;
        cout << endl;
        
        temp = temp->next;
        no++;
    }
}

void addLast(Node* &head, string kode, string tujuan, string status) {
    Node* nodeBaru = new Node;
    nodeBaru->data.kode = kode;
    nodeBaru->data.tujuan = tujuan;
    nodeBaru->data.status = status;
    nodeBaru->next = nullptr;
    
    if (head == nullptr) {
        head = nodeBaru;
        return;
    }
    
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = nodeBaru;
}

void addMiddle(Node* &head, string kode, string tujuan, string status, int posisi) {
    if (posisi <= 1) {
        Node* nodeBaru = new Node;
        nodeBaru->data.kode = kode;
        nodeBaru->data.tujuan = tujuan;
        nodeBaru->data.status = status;
        nodeBaru->next = head;
        head = nodeBaru;
        return;
    }
    
    Node* temp = head;
    int hitung = 1;
    
    while (temp != nullptr && hitung < posisi - 1) {
        temp = temp->next;
        hitung++;
    }
    
    if (temp == nullptr) {
        cout << "Posisi terlalu jauh!" << endl;
        return;
    } else {
        Node* nodeBaru = new Node;
        nodeBaru->data.kode = kode;
        nodeBaru->data.tujuan = tujuan;
        nodeBaru->data.status = status;
        nodeBaru->next = temp->next;
        temp->next = nodeBaru;
    }
}

void deleteFirst(Node* &head) {
    if (head == nullptr) {
        cout << "Tidak ada jadwal yang bisa dihapus!" << endl;
        return;
    }
    
    Node* temp = head;
    cout << "\n--- Hapus Jadwal Awal ---" << endl;
    cout << "Jadwal yang dihapus:" << endl;
    cout << "Kode: " << temp->data.kode << endl;
    cout << "Tujuan: " << temp->data.tujuan << endl;
    cout << "Status: " << temp->data.status << endl;
    
    head = head->next;
    delete temp;
    
    cout << "Jadwal berhasil dihapus!" << endl;
}

void editData(Node* &head, string kodeInput) {
    if (head == nullptr) {
        cout << "Tidak ada jadwal untuk diupdate!" << endl;
        return;
    }
    
    Node* temp = head;
    bool ketemu = false;
    
    while (temp != nullptr) {
        if (temp->data.kode == kodeInput) {
            ketemu = true;
            break;
        }
        temp = temp->next;
    }
    
    if (ketemu == false) {
        cout << "Kode penerbangan tidak ditemukan!" << endl;
        return;
    }
    cout << "\nData penerbangan:" << endl;
    cout << "Kode: " << temp->data.kode << endl;
    cout << "Tujuan: " << temp->data.tujuan << endl;
    cout << "Status saat ini: " << temp->data.status << endl;
    
    string statusBaru;
    cout << "\nMasukkan status baru: ";
    getline(cin, statusBaru);
    
    cout << "Status lama: " << temp->data.status << endl;
    temp->data.status = statusBaru;
    cout << "Status berhasil diubah menjadi: " << temp->data.status << endl;
}

void clearList(Node* &head) {
    Node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
    cout << "Semua data berhasil dihapus." << endl;
}

void menu() {
    cout << "\n================================" << endl;
    cout << "   SISTEM JADWAL PENERBANGAN" << endl;
    cout << "     Rasyid - 2409106042" << endl;
    cout << "================================" << endl;
    cout << "1. Tambah Jadwal Penerbangan" << endl;
    cout << "2. Sisipkan Jadwal Penerbangan" << endl;
    cout << "3. Hapus Jadwal Paling Awal" << endl;
    cout << "4. Update Status Penerbangan" << endl;
    cout << "5. Tampilkan Semua Jadwal" << endl;
    cout << "0. Keluar" << endl;
    cout << "================================" << endl;
    cout << "Pilihan: ";
}

void tambahJadwal() {
    string kode = buatKode();
    counter++;
    string tujuan, status;
    cout << "\n--- Tambah Jadwal Baru ---" << endl;
    cout << "Kode Penerbangan: " << kode << endl;
    cout << "Masukkan tujuan: ";
    cin.ignore();
    getline(cin, tujuan);
    cout << "Masukkan status: ";
    getline(cin, status);
    addLast(head, kode, tujuan, status);
    cout << "Jadwal berhasil ditambahkan!" << endl;
}

void sisipkanJadwal() {
    if (isEmpty()) {
        cout << "List masih kosong!" << endl;
        return;
    }
    int posisi = 3; //digit terakhir NIM (2) + 1
    string kode = buatKode();
    counter++;
    
    string tujuan, status;
    cout << "\n--- Sisipkan Jadwal ---" << endl;
    cout << "Posisi sisip: " << posisi << endl;
    cout << "Kode Penerbangan: " << kode << endl;
    cout << "Masukkan tujuan: ";
    cin.ignore();
    getline(cin, tujuan);
    cout << "Masukkan status: ";
    getline(cin, status);
    
    addMiddle(head, kode, tujuan, status, posisi);
    cout << "Jadwal berhasil disisipkan!" << endl;
}

void updateStatus() {
    if (isEmpty()) {
        cout << "Tidak ada jadwal untuk diupdate!" << endl;
        return;
    }
    string kodeInput;
    cout << "\n--- Update Status Penerbangan ---" << endl;
    cout << "Masukkan kode penerbangan: ";
    cin.ignore();
    getline(cin, kodeInput);
    editData(head, kodeInput);
}

int main() {
    int pilihan;
    
    do {
        menu();
        cin >> pilihan;
        
        if (pilihan == 1) {
            tambahJadwal();
        } else if (pilihan == 2) {
            sisipkanJadwal();
        } else if (pilihan == 3) {
            deleteFirst(head);
        } else if (pilihan == 4) {
            updateStatus();
        } else if (pilihan == 5) {
            display(head);
        } else if (pilihan == 0) {
            cout << "Terima kasih!" << endl;
            clearList(head);
        } else {
            cout << "Pilihan tidak valid!" << endl;
        }
        
    } while (pilihan != 0);
    
    return 0;
}