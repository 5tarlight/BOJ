#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long s, e;
        cin >> s >> e;
        int gap = e - s;

        long n = 0;
        for (;gap > n * (n + 1); n++);

        if (gap <= n * n)
            cout << n * 2 - 1 << '\n';
        else
            cout << n * 2 << '\n';
    }
}
