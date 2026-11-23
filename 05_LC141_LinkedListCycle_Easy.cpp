#include <iostream>
#include <vector>
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
    int n, pos;
    cin >> n;

    vector<int> values(n);
    for (int i = 0; i < n; i++) cin >> values[i];
    cin >> pos; // Index where the last node connects; -1 means no cycle.

    if (n == 0) {
        cout << "false" << endl;
        return 0;
    }

    vector<Node*> nodes;
    for (int i = 0; i < n; i++) nodes.push_back(new Node(values[i]));

    for (int i = 0; i < n - 1; i++) nodes[i]->next = nodes[i + 1];
    if (pos >= 0 && pos < n) nodes[n - 1]->next = nodes[pos];

    Node* slow = nodes[0];
    Node* fast = nodes[0];
    bool hasCycle = false;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            hasCycle = true;
            break;
        }
    }

    cout << (hasCycle ? "true" : "false") << endl;

    // Do not follow the cycle while freeing nodes.
    for (Node* node : nodes) delete node;
    return 0;
}
