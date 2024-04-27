#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int a = 0;
    for (int i = 0; i < 9; i++) {
        int num;
        cin >> num;
        a += num;
    }

    int b = 0;
    for (int i = 0; i < 8; i++) {
        int num;
        cin >> num;
        b += num;
    }

    cout << a - b + 1 << '\n';
}
