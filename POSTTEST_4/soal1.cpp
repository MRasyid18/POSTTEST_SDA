#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
};

void push(Node*& top, char data) {
    Node* newNode = new Node{data, top};
    top = newNode;
}

char pop(Node*& top) {
    if (top == nullptr) return '\0';
    Node* temp = top;
    char poppedValue = temp->data;
    top = top->next;
    delete temp;
    return poppedValue;
}

string reverseString(string s) {
    Node* stackTop = nullptr;
    string reversed = "";

    // Masukin semua karakter ke stack
    for (char c : s) {
        push(stackTop, c);
    }           //Pertama looping tiap huruf string s, lalu push ke stack → otomatis numpuk.

    // Ambil balik semua karakter dari stack
    while (stackTop != nullptr) {
        reversed += pop(stackTop);
    }   //Lalu, selama stack masih ada isinya, ambil (pop) satu per satu, 
        //hasilnya otomatis jadi kebalik urutannya.
    return reversed;
}

int main() {
    string text = "Struktur Data";
    cout << "Teks asli: " << text << endl;
    cout << "Teks terbalik: " << reverseString(text) << endl;
    return 0;
}