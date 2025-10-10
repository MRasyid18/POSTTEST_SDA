#include <iostream>
using namespace std;

// Struktur Node untuk Binary Tree
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

// Fungsi buat masukin data ke tree (insert)
Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val); // kalau kosong, buat node baru
    }
    if (val < root->data) {
        root->left = insert(root->left, val); // masuk ke kiri
    } else if (val > root->data) {
        root->right = insert(root->right, val); // masuk ke kanan
    }
    return root;
}

// Fungsi buat ngitung jumlah semua node di tree
int countNodes(Node* root) {
    if (root == nullptr)
        return 0; // kalau kosong, hitungannya 0

    // hitung 1 untuk node sekarang, tambah node kiri dan kanan
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);

    cout << "Jumlah total node dalam tree adalah: " << countNodes(root) << endl; // Output: 4
    return 0;
}
