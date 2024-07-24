#include <iostream>
#include <algorithm>

using namespace std;

int op[4];
int n;
int a[11];
int amax = -1e9, amin = 1e9;

void backtrack(int d, int v) {
    if (d == n) {
        amax = max(amax, v);
        amin = min(amin, v);
    }

    for (int i = 0; i < 4; i++) {
        if (op[i] == 0) continue;

        op[i]--;
        if (i == 0) backtrack(d + 1, v + a[d]);
        else if (i == 1) backtrack(d + 1, v - a[d]);
        else if (i == 2) backtrack(d + 1, v * a[d]);
        else if (i == 3) backtrack(d + 1, v / a[d]);
        op[i]++;
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < 4; i++)
        cin >> op[i];

    backtrack(1, a[0]);

    cout << amax << '\n' << amin;
}
