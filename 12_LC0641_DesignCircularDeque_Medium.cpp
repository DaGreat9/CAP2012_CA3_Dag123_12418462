#include <iostream>
#include <vector>
#include <string>
using namespace std;

class MyCircularDeque {
    vector<int> data;
    int frontIndex, rearIndex, count, capacity;
public:
    MyCircularDeque(int k) {
        capacity = k;
        data.resize(k);
        frontIndex = 0;
        rearIndex = k - 1;
        count = 0;
    }

    bool insertFront(int value) {
        if (isFull()) return false;
        frontIndex = (frontIndex - 1 + capacity) % capacity;
        data[frontIndex] = value;
        count++;
        if (count == 1) rearIndex = frontIndex;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;
        rearIndex = (rearIndex + 1) % capacity;
        data[rearIndex] = value;
        count++;
        if (count == 1) frontIndex = rearIndex;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;
        frontIndex = (frontIndex + 1) % capacity;
        count--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;
        rearIndex = (rearIndex - 1 + capacity) % capacity;
        count--;
        return true;
    }

    int getFront() { return isEmpty() ? -1 : data[frontIndex]; }
    int getRear() { return isEmpty() ? -1 : data[rearIndex]; }
    bool isEmpty() { return count == 0; }
    bool isFull() { return count == capacity; }
};

int main() {
    int k, q;
    cin >> k >> q;
    MyCircularDeque deque(k);

    // Commands: insertFront x, insertLast x, deleteFront, deleteLast,
    // getFront, getRear, isEmpty, isFull.
    while (q--) {
        string command;
        cin >> command;

        if (command == "insertFront" || command == "insertLast") {
            int x; cin >> x;
            cout << (command == "insertFront" ? deque.insertFront(x) : deque.insertLast(x)) << endl;
        } else if (command == "deleteFront") {
            cout << deque.deleteFront() << endl;
        } else if (command == "deleteLast") {
            cout << deque.deleteLast() << endl;
        } else if (command == "getFront") {
            cout << deque.getFront() << endl;
        } else if (command == "getRear") {
            cout << deque.getRear() << endl;
        } else if (command == "isEmpty") {
            cout << deque.isEmpty() << endl;
        } else if (command == "isFull") {
            cout << deque.isFull() << endl;
        }
    }
    return 0;
}
