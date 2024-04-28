#include <iostream>
#include <algorithm>

using namespace std;

char roll(char a, int d) {
    char c = a + d;
    if (c > 'Z') {
        c = 'A' + (c - 'Z' - 1);
    }
    return c;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    char a[n + 1];
    cin >> a;

    int idx = 0;
    while (idx < n && k > 0) {
        int dist = 'Z' - a[idx] + 1;
        int goal = min(dist % 26, k);
        if (a[idx] < roll(a[idx], goal)) {
            idx++;
            continue;
        }

        a[idx] = roll(a[idx], goal);
        k -= goal;
        idx++;
    }

    if (k > 0)
        a[n - 1] = roll(a[n - 1], k % 26);

    cout << a << endl;
}
