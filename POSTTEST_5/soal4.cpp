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
        root->left = insert(root->left, val);
    } else if (val > root->data) {
        root->right = insert(root->right, val);
    }
    return root;
}

// Fungsi buat traversal post-order (kiri -> kanan -> root)
void postOrderTraversal(Node* root) {
    if (root == nullptr)
        return; // kalau kosong, berhenti

    postOrderTraversal(root->left);  // kunjungi kiri dulu
    postOrderTraversal(root->right); // lalu kanan
    cout << root->data << " ";       // terakhir baru cetak root-nya
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

    cout << "Post-order traversal dari tree adalah: ";
    postOrderTraversal(root); // Output: 20 40 30 60 80 70 50
    cout << endl;
    return 0;
}
