#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q1, q2;
    int n;
    cin >> n; // Number of values to push.

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    if (!q1.empty()) {
        cout << "Top: " << q1.front() << endl;
        cout << "Popping: ";
        while (!q1.empty()) {
            cout << q1.front() << " ";
            q1.pop();
        }
        cout << endl;
    } else {
        cout << "Stack is empty" << endl;
    }

    return 0;
}
