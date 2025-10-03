#include <iostream>
#include <string>
using namespace std;

struct Node {
    string document;
    Node* next;
};

void enqueue(Node*& front, Node*& rear, string document) {
    Node* newNode = new Node{document, nullptr};

    // Jika queue kosong
    if (front == nullptr) {
        front = rear = newNode;
    } else {
        // Jika queue sudah ada isinya
        rear->next = newNode;
        rear = newNode;
    }
}

string dequeue(Node*& front, Node*& rear) {
    if (front == nullptr) return ""; // Queue kosong

    // Simpan data dari front
    string doc = front->document;

    // Pindahkan front ke node berikutnya
    Node* temp = front;
    front = front->next;

    // Jika setelah dipindah, queue kosong → rear juga diset kosong
    if (front == nullptr) {
        rear = nullptr;
    }

    // Hapus node lama
    delete temp;

    return doc;
}

void processAllDocuments(Node*& front, Node*& rear) {
    while (front != nullptr) {
        string doc = dequeue(front, rear);
        cout << "Memproses: " << doc << endl;
    }
}

int main() {
    Node* front = nullptr;
    Node* rear = nullptr;

    enqueue(front, rear, "Document1.pdf");
    enqueue(front, rear, "Report.docx");
    enqueue(front, rear, "Presentation.pptx");

    cout << "Memulai pemrosesan antrian printer:" << endl;
    processAllDocuments(front, rear);

    return 0;
}
