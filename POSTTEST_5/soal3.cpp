#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// fungsi insert buat bikin tree
Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val); // kiri
    } else if (val > root->data) {
        root->right = insert(root->right, val); // kanan
    }
    return root;
}

// Fungsi buat cari nilai paling besar di tree
int findMaxValue(Node* root) {
    if (root == nullptr)
        return -1; // kalau kosong, balikin -1

    // terus ke kanan sampai mentok
    while (root->right != nullptr) {
        root = root->right; // pindah ke anak kanan
    }

    return root->data; // node paling kanan = nilai terbesar
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 80);

    cout << "Nilai terbesar dalam tree adalah: " << findMaxValue(root) << endl; // Output: 80
    return 0;
}
