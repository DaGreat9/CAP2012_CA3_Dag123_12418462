#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    vector<int> all;
    for (int x : a) all.push_back(x);
    for (int x : b) all.push_back(x);

    sort(all.begin(), all.end());

    int total = all.size();
    if (total == 0) return 0;

    double median;
    if (total % 2 == 1) {
        median = all[total / 2];
    } else {
        median = (all[total / 2 - 1] + all[total / 2]) / 2.0;
    }

    cout << median << endl;
    return 0;
}
