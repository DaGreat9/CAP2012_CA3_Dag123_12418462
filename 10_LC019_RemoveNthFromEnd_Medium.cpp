#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = NULL;
    }
};

int main() {
    int n, position;
    cin >> n;

    Node* head = NULL;
    Node* tail = NULL;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        Node* node = new Node(x);
        if (head == NULL) head = tail = node;
        else { tail->next = node; tail = node; }
    }

    cin >> position; // Position counted from the end.

    Node dummy(0);
    dummy.next = head;
    Node* first = &dummy;
    Node* second = &dummy;

    for (int i = 0; i <= position && first != NULL; i++)
        first = first->next;

    while (first != NULL) {
        first = first->next;
        second = second->next;
    }

    if (second->next != NULL) {
        Node* temp = second->next;
        second->next = temp->next;
        delete temp;
    }

    head = dummy.next;
    while (head != NULL) {
        cout << head->data << " ";
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    cout << endl;
    return 0;
}
