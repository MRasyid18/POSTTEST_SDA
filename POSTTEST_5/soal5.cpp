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

// fungsi insert buat isi data ke tree
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

// Fungsi traversal pre-order (root -> kiri -> kanan)
void preOrderTraversal(Node* root) {
    if (root == nullptr)
        return; // kalau kosong, stop

    cout << root->data << " ";      // cetak root dulu
    preOrderTraversal(root->left);  // terus ke kiri
    preOrderTraversal(root->right); // terakhir ke kanan
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Pre-order traversal dari tree adalah: ";
    preOrderTraversal(root); // Output: 50 30 20 40 70 60 80
    cout << endl;
    return 0;
}
