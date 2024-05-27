#include <iostream>
#include <algorithm>

using namespace std;

int k, c;
int a[10];
bool used[10];
bool found = false;

void backtrack(int d, int cap) {
    if (d == 10) {
        if (cap == c)
            found = true;
        return;
    }

    if (found)
        return;

    used[d] = true;
    backtrack(d + 1, cap + a[d]);
    used[d] = false;
    backtrack(d + 1, cap);
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        found = false;
        fill(used, used + 10, false);

        cin >> k >> c;
        for (int i = 0; i < 10; i++)
            cin >> a[i];

        backtrack(0, 0);
        cout << k << ' ' << (found ? "YES" : "NO") << '\n';
    }
}
