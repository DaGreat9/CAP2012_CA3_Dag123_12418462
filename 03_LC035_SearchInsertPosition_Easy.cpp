#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, target;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> target;

    int left = 0, right = n - 1, answer = n;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (a[mid] >= target) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << answer << endl;
    return 0;
}
