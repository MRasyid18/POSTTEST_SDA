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

// fungsi buat masukin data ke tree
Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val); // ke kiri
    } else if (val > root->data) {
        root->right = insert(root->right, val); // ke kanan
    }
    return root;
}

// Fungsi buat cari nilai paling kecil di tree
int findMinValue(Node* root) {
    if (root == nullptr)
        return -1; // kalau kosong, balikin -1

    // terus ke kiri sampai mentok
    while (root->left != nullptr) {
        root = root->left; // pindah ke anak kiri
    }

    return root->data; // node paling kiri = nilai terkecil
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);

    cout << "Nilai terkecil dalam tree adalah: " << findMinValue(root) << endl; // Output: 20
    return 0;
}
