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

bool areBracketsBalanced(string expr) {
    Node* stackTop = nullptr;

    for (char c : expr) {
        // Kalau ketemu kurung buka, taruh di stack
        if (c == '(' || c == '{' || c == '[') {
            push(stackTop, c);
        }
        // Kalau ketemu kurung tutup, cek pasangannya
        else if (c == ')' || c == '}' || c == ']') {
            if (stackTop == nullptr) return false; // stack kosong padahal ada kurung tutup
            char topChar = pop(stackTop);          // ambil kurung buka terakhir
            if ((c == ')' && topChar != '(') ||
                (c == '}' && topChar != '{') ||
                (c == ']' && topChar != '[')) {
                return false; // kalau ga cocok -> tidak seimbang
            }
        }
    }

    // kalau stack kosong, berarti semua kurung sudah dapat pasangannya
    return (stackTop == nullptr);
}

int main() {
    string expr1 = "{[()]}";
    cout << expr1 << " -> " << (areBracketsBalanced(expr1) ? "Seimbang" : "Tidak Seimbang") << endl;

    string expr2 = "{[(])}";
    cout << expr2 << " -> " << (areBracketsBalanced(expr2) ? "Seimbang" : "Tidak Seimbang") << endl;

    return 0;
}
