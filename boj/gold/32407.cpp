#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int n;
map<int,int> cnt;
int L;

bool ok(int x) {
    vector<int> cap(L, x);

    for (auto &[a, c]: cnt) {
        long long sum = 0;
        vector<int> mn(a);

        for (int r = 0; r < a; r++) {
            int m = 1e9;
            for (int d = r; d < L; d += a)
                m = min(m, cap[d]);

            mn[r] = m;
            sum += m;
        }

        if (sum < c) return false;

        int rem = c;
        for (int r = 0; r < a && rem; r++) {
            int g = min(mn[r], rem);
            for (int d = r; d < L; d += a)
                cap[d] -= g;
            rem -= g;
        }
    }

    return true;
}

int main() {
    fio();

    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x, cnt[x]++, L = max(L, x);

    int l = 1, r = n, ans = n;
    while (l <= r) {
        int m = (l + r) / 2;
        if (ok(m)) ans = m, r = m - 1;
        else l = m + 1;
    }

    cout << ans;
}
