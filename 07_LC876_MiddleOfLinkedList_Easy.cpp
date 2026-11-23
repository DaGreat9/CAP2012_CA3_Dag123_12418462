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
    int n;
    cin >> n;

    Node* head = NULL;
    Node* tail = NULL;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        Node* node = new Node(x);

        if (head == NULL) head = tail = node;
        else {
            tail->next = node;
            tail = node;
        }
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    if (slow != NULL) cout << slow->data << endl;

    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}
