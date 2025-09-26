#include <iostream>
#include <string>
using namespace std;

// Muhammad Rasyid
// 2409106042

struct penerbangan {
    string kode;
    string tujuan;
    string status;
};

struct Node {
    penerbangan data;
    Node* next;
    Node* prev;
};

Node* head = nullptr;
Node* tail = nullptr;
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

// Traversal maju (head -> tail)
void displayForward(Node* head) {
    if (head == nullptr) {
        cout << "Tidak ada jadwal penerbangan" << endl;
        return;
    }
    
    cout << "\n--- Daftar Jadwal Penerbangan (Forward) ---" << endl;
    Node* temp = head;
    int no = 1;
    
    while (temp != nullptr) {
        cout << "Jadwal " << no << ":" << endl;
        cout << "  Kode   : " << temp->data.kode << endl;
        cout << "  Tujuan : " << temp->data.tujuan << endl;
        cout << "  Status : " << temp->data.status << endl;
        cout << endl;
        temp = temp->next;
        no++;
    }
}

// Traversal mundur (tail -> head)
void displayBackward(Node* tail) {
    if (tail == nullptr) {
        cout << "Tidak ada jadwal penerbangan" << endl;
        return;
    }

    cout << "\n--- Daftar Jadwal Penerbangan (Backward) ---" << endl;
    Node* temp = tail;
    int no = 1;

    while (temp != nullptr) {
        cout << "Jadwal " << no << ":" << endl;
        cout << "  Kode   : " << temp->data.kode << endl;
        cout << "  Tujuan : " << temp->data.tujuan << endl;
        cout << "  Status : " << temp->data.status << endl;
        cout << endl;
        temp = temp->prev;
        no++;
    }
}

// Tambah di akhir
void addLast(Node* &head, Node* &tail, string kode, string tujuan, string status) {
    Node* nodeBaru = new Node;
    nodeBaru->data.kode = kode;
    nodeBaru->data.tujuan = tujuan;
    nodeBaru->data.status = status;
    nodeBaru->next = nullptr;
    nodeBaru->prev = tail;

    if (head == nullptr) {
        head = nodeBaru;
        tail = nodeBaru;
    } else {
        tail->next = nodeBaru;
        tail = nodeBaru;
    }
}

// Tambah di tengah (posisi)
void addMiddle(Node* &head, Node* &tail, string kode, string tujuan, string status, int posisi) {
    if (posisi <= 1) { 
        // insert di awal
        Node* nodeBaru = new Node;
        nodeBaru->data = {kode, tujuan, status};
        nodeBaru->prev = nullptr;
        nodeBaru->next = head;
        if (head != nullptr) head->prev = nodeBaru;
        else tail = nodeBaru; 
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
        nodeBaru->data = {kode, tujuan, status};
        nodeBaru->next = temp->next;
        nodeBaru->prev = temp;

        if (temp->next != nullptr)
            temp->next->prev = nodeBaru;
        else
            tail = nodeBaru;
        temp->next = nodeBaru;
    }
}

// Hapus data pertama
void deleteFirst(Node* &head, Node* &tail) {
    if (head == nullptr) {
        cout << "Tidak ada jadwal yang bisa dihapus!" << endl;
        return;
    }

    Node* temp = head;
    cout << "\n--- Hapus Jadwal Awal ---" << endl;
    cout << "Jadwal yang dihapus:" << endl;
    cout << "Kode   : " << temp->data.kode << endl;
    cout << "Tujuan : " << temp->data.tujuan << endl;
    cout << "Status : " << temp->data.status << endl;

    head = head->next;
    if (head != nullptr) head->prev = nullptr;
    else tail = nullptr;

    delete temp;
    cout << "Jadwal berhasil dihapus!" << endl;
}

// Update status berdasarkan kode
void editData(Node* &head, string kodeInput) {
    if (head == nullptr) {
        cout << "Tidak ada jadwal untuk diupdate!" << endl;
        return;
    }

    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data.kode == kodeInput) {
            cout << "\nData penerbangan:" << endl;
            cout << "Kode   : " << temp->data.kode << endl;
            cout << "Tujuan : " << temp->data.tujuan << endl;
            cout << "Status : " << temp->data.status << endl;

            string statusBaru;
            cout << "\nMasukkan status baru: ";
            cin.ignore();
            getline(cin, statusBaru);

            temp->data.status = statusBaru;
            cout << "Status berhasil diubah menjadi: " << temp->data.status << endl;
            return;
        }
        temp = temp->next;
    }

    cout << "Kode penerbangan tidak ditemukan!" << endl;
}

// Cari data berdasarkan kode atau tujuan
void cariData(Node* head) {
    if (head == nullptr) {
        cout << "List masih kosong!" << endl;
        return;
    }

    cout << "\n--- Cari Data Jadwal ---" << endl;
    cout << "Cari berdasarkan (1) Kode atau (2) Tujuan? ";
    int pilih; cin >> pilih;
    cin.ignore();

    string key;
    if (pilih == 1) {
        cout << "Masukkan kode penerbangan: ";
        getline(cin, key);
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data.kode == key) {
                cout << ">> Data ditemukan:" << endl;
                cout << "Kode   : " << temp->data.kode << endl;
                cout << "Tujuan : " << temp->data.tujuan << endl;
                cout << "Status : " << temp->data.status << endl;
                return;
            }
            temp = temp->next;
        }
    } else {
        cout << "Masukkan tujuan penerbangan: ";
        getline(cin, key);
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data.tujuan == key) {
                cout << ">> Data ditemukan:" << endl;
                cout << "Kode   : " << temp->data.kode << endl;
                cout << "Tujuan : " << temp->data.tujuan << endl;
                cout << "Status : " << temp->data.status << endl;
                return;
            }
            temp = temp->next;
        }
    }

    cout << "Data tidak ditemukan!" << endl;
}

void clearList(Node* &head, Node* &tail) {
    Node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
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
    cout << "5. Tampilkan Semua Jadwal (Maju)" << endl;
    cout << "6. Tampilkan Semua Jadwal (Mundur)" << endl;
    cout << "7. Cari Detail Jadwal" << endl;
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
    addLast(head, tail, kode, tujuan, status);
    cout << "Jadwal berhasil ditambahkan!" << endl;
}

void sisipkanJadwal() {
    if (isEmpty()) {
        cout << "List masih kosong!" << endl;
        return;
    }
    int posisi = 3; // digit terakhir NIM (2) + 1
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

    addMiddle(head, tail, kode, tujuan, status, posisi);
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
            deleteFirst(head, tail);
        } else if (pilihan == 4) {
            updateStatus();
        } else if (pilihan == 5) {
            displayForward(head);
        } else if (pilihan == 6) {
            displayBackward(tail);
        } else if (pilihan == 7) {
            cariData(head);
        } else if (pilihan == 0) {
            cout << "Terima kasih!" << endl;
            clearList(head, tail);
        } else {
            cout << "Pilihan tidak valid!" << endl;
        }
        
    } while (pilihan != 0);
    
    return 0;
}
