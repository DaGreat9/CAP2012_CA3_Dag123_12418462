#include <iostream>
#include <string>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = NULL;
    }
};

class MyLinkedList {
    Node* head;
public:
    MyLinkedList() { head = NULL; }

    int get(int index) {
        Node* current = head;
        for (int i = 0; current != NULL && i < index; i++)
            current = current->next;
        return current == NULL ? -1 : current->data;
    }

    void addAtHead(int value) {
        Node* node = new Node(value);
        node->next = head;
        head = node;
    }

    void addAtTail(int value) {
        Node* node = new Node(value);
        if (head == NULL) { head = node; return; }
        Node* current = head;
        while (current->next != NULL) current = current->next;
        current->next = node;
    }

    void addAtIndex(int index, int value) {
        if (index == 0) { addAtHead(value); return; }
        Node* current = head;
        for (int i = 0; current != NULL && i < index - 1; i++)
            current = current->next;
        if (current == NULL) return;
        Node* node = new Node(value);
        node->next = current->next;
        current->next = node;
    }

    void deleteAtIndex(int index) {
        if (head == NULL || index < 0) return;
        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* current = head;
        for (int i = 0; current->next != NULL && i < index - 1; i++)
            current = current->next;
        if (current->next != NULL) {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
        }
    }

    void display() {
        Node* current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    MyLinkedList list;
    int q;
    cin >> q; // Commands: addAtHead x, addAtTail x, addAtIndex i x, get i, deleteAtIndex i, display

    while (q--) {
        string command;
        cin >> command;

        if (command == "addAtHead") {
            int x; cin >> x; list.addAtHead(x);
        } else if (command == "addAtTail") {
            int x; cin >> x; list.addAtTail(x);
        } else if (command == "addAtIndex") {
            int i, x; cin >> i >> x; list.addAtIndex(i, x);
        } else if (command == "get") {
            int i; cin >> i; cout << list.get(i) << endl;
        } else if (command == "deleteAtIndex") {
            int i; cin >> i; list.deleteAtIndex(i);
        } else if (command == "display") {
            list.display();
        }
    }
    return 0;
}
