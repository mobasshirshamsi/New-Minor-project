#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* insert(Node* head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) return newNode;
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    return head;
}

Node* merge(Node* l1, Node* l2) {
    if (!l1) return l2;
    if (!l2) return l1;

    Node* result = nullptr;

    if (l1->data < l2->data) {
        result = l1;
        result->next = merge(l1->next, l2);
    } else {
        result = l2;
        result->next = merge(l1, l2->next);
    }

    return result;
}

void print(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Example usage
int main() {
    Node* list1 = nullptr;
    Node* list2 = nullptr;

    list1 = insert(list1, 1);
    list1 = insert(list1, 3);
    list1 = insert(list1, 5);

    list2 = insert(list2, 2);
    list2 = insert(list2, 4);
    list2 = insert(list2, 6);

    Node* merged = merge(list1, list2);
    print(merged);

    return 0;
}
