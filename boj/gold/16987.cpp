#include <iostream>
#include <algorithm>

using namespace std;

int n;
int a[8];
int w[8];
int ans = 0;

void backtrack(int idx) {
    if (idx == n) {
        int cnt = 0;
        for (int i = 0; i < n; i++)
            if (a[i] <= 0)
                cnt++;
        ans = max(ans, cnt);
        return;
    }

    if (a[idx] <= 0) {
        backtrack(idx + 1);
        return;
    }

    bool broke = false;
    for (int i = 0; i < n; i++) {
        if (i == idx || a[i] <= 0) {
            continue;
        }

        int prevIdx = a[idx];
        int prevTarget = a[i];
        a[i] -= w[idx];
        a[idx] -= w[i];
        backtrack(idx + 1);
        a[i] = prevTarget;
        a[idx] = prevIdx;
        broke = true;
    }

    if (!broke)
        backtrack(idx + 1);
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i] >> w[i];

    backtrack(0);

    cout << ans;
}
