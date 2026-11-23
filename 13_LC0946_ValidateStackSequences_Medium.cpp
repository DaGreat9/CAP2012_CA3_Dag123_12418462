#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> pushed(n), popped(n);
    for (int i = 0; i < n; i++) cin >> pushed[i];
    for (int i = 0; i < n; i++) cin >> popped[i];

    stack<int> s;
    int j = 0;

    for (int i = 0; i < n; i++) {
        s.push(pushed[i]);

        while (!s.empty() && j < n && s.top() == popped[j]) {
            s.pop();
            j++;
        }
    }

    cout << (j == n ? "true" : "false") << endl;
    return 0;
}
