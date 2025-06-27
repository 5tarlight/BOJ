#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void fio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main() {
    fio();

    string s;
    if (!getline(cin, s)) return 0;
    int n = s.size();

    vector<int> d1(n), d2(n);

    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r ? 1 : min(d1[l + r - i], r - i + 1));
        while (i - k >= 0 && i + k < n && s[i - k] == s[i + k]) ++k;
        d1[i] = k;
        if (i + k - 1 > r) {
            l = i - k + 1;
            r = i + k - 1;
        }
    }

    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r ? 0 : min(d2[l + r - i + 1], r - i + 1));
        while (i - k - 1 >= 0 && i + k < n && s[i - k - 1] == s[i + k]) ++k;
        d2[i] = k;
        if (i + k - 1 > r) {
            l = i - k;
            r = i + k - 1;
        }
    }

    static int nxt[26][100005], prv[26][100005];
    for (int c = 0; c < 26; c++) {
        nxt[c][n] = n;
        for (int i = n - 1; i >= 0; i--)
            nxt[c][i] = (s[i] - 'a' == c ? i : nxt[c][i + 1]);

        prv[c][0] = (s[0] - 'a' == c ? 0 : -1);
        for (int i = 1; i < n; i++)
            prv[c][i] = (s[i] - 'a' == c ? i : prv[c][i - 1]);
    }

    int ans = 1;
    for (int i = 0; i < n; i++) {
        ans = max(ans, 2 * d1[i] - 1);
        ans = max(ans, 2 * d2[i]);
    }

    auto odd = [&](int i) {
        int arm = d1[i] - 1;
        int l0 = i - arm, r0 = i + arm;

        if (l0 > 0 && r0 < n - 1) {
            int c = s[l0 - 1] - 'a';
            int t = nxt[c][r0 + 1];
            if (t < n) {
                int ext = 0;
                for (int l = l0 - 2, r = t + 1; l >= 0 && r < n && s[l] == s[r]; --l, ++r) ++ext;
                ans = max(ans, 2 * (arm + ext + 1) + 1);
            }
        }

        if (l0 > 0 && r0 < n - 1) {
            int c = s[r0 + 1] - 'a';
            int t = prv[c][l0 - 1];
            if (t >= 0) {
                int ext = 0;
                for (int l = t - 1, r = r0 + 2; l >= 0 && r < n && s[l] == s[r]; --l, ++r) ++ext;
                ans = max(ans, 2 * (arm + ext + 1) + 1);
            }
        }
    };

    auto even = [&](int i) {
        int arm = d2[i];
        int l0 = i - arm, r0 = i + arm - 1;

        if (l0 > 0 && r0 < n - 1) {
            int c = s[l0 - 1] - 'a';
            int t = nxt[c][r0 + 1];
            if (t < n) {
                int ext = 0;
                for (int l = l0 - 2, r = t + 1; l >= 0 && r < n && s[l] == s[r]; --l, ++r) ++ext;
                ans = max(ans, 2 * (arm + ext + 1));
            }
        }

        if (l0 > 0 && r0 < n - 1) {
            int c = s[r0 + 1] - 'a';
            int t = prv[c][l0 - 1];
            if (t >= 0) {
                int ext = 0;
                for (int l = t - 1, r = r0 + 2; l >= 0 && r < n && s[l] == s[r]; --l, ++r) ++ext;
                ans = max(ans, 2 * (arm + ext + 1));
            }
        }
    };

    for (int i = 0; i < n; i++) {
        odd(i);
        even(i);
    }

    cout << ans;
}
