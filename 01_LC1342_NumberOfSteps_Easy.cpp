#include <iostream>
using namespace std;

int main() {
    int num, steps = 0;
    cin >> num;

    while (num > 0) {
        if (num % 2 == 0)
            num = num / 2;
        else
            num = num - 1;
        steps++;
    }

    cout << steps << endl;
    return 0;
}
