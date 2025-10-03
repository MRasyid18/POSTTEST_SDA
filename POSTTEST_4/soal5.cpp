#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

/*
 * Fungsi ini menerima referensi ke pointer head.
 * Setelah penukaran, head_ref akan menunjuk ke node baru (tail lama).
 */
void exchangeHeadAndTail(Node *&head_ref) {
    // Jika list kosong atau hanya ada 1 node → tidak perlu ditukar
    if (head_ref == nullptr || head_ref->next == head_ref) {
        return;
    }

    Node* head = head_ref;
    Node* tail = head_ref->prev;   // tail adalah prev dari head
    Node* headNext = head->next;   // node setelah head
    Node* tailPrev = tail->prev;   // node sebelum tail

    // Kasus khusus: hanya ada 2 node
    if (headNext == tail) {
        // Swap sederhana: tail jadi head
        head_ref = tail;
        return;
    }

    // 1. Hubungkan tail dengan headNext
    tail->next = headNext;
    headNext->prev = tail;

    // 2. Hubungkan head dengan tailPrev
    head->prev = tailPrev;
    tailPrev->next = head;

    // 3. Sambungkan head dan tail satu sama lain
    tail->prev = head;
    head->next = tail;

    // 4. Update head_ref ke tail (karena tail sekarang jadi head baru)
    head_ref = tail;
}

void printList(Node *head_ref)
{
    if (head_ref == nullptr)
    {
        cout << "List kosong" << endl;
        return;
    }

    Node *current = head_ref;
    do
    {
        cout << current->data << " ";
        current = current->next;
    } while (current != head_ref);
    cout << endl;
}

void insertEnd(Node *&head_ref, int data)
{
    Node *newNode = new Node{data, nullptr, nullptr};

    if (head_ref == nullptr)
    {
        newNode->next = newNode;
        newNode->prev = newNode;
        head_ref = newNode;
        return;
    }

    Node *tail = head_ref->prev;
    newNode->next = head_ref;
    newNode->prev = tail;
    head_ref->prev = newNode;
    tail->next = newNode;
}

int main()
{
    Node *head = nullptr;

    // Buat list: 1 <-> 2 <-> 3 <-> 4 <-> 5
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 4);
    insertEnd(head, 5);

    cout << "List sebelum exchange: ";
    printList(head);

    exchangeHeadAndTail(head);

    cout << "List setelah exchange head dan tail: ";
    // Expected output: 5 2 3 4 1
    printList(head);

    return 0;
}
