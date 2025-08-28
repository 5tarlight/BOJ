#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int main() {
    fio();

    int n; cin >> n;
    bool canZero[10];
    memset(canZero, true, sizeof(canZero));
    pair<long long, char> a[10];

    for (int i = 0; i < 10; i++) a[i] = {0, (char)('A' + i)};

    string s[n];
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        canZero[s[i][0] - 'A'] = false;

        long long tmp = 1;
        for (int j = s[i].size() - 1; j >= 0; j--) {
            a[s[i][j] - 'A'].first += tmp;
            tmp *= 10;
        }
    }

    sort(a, a + 10, greater<>());

    int zeroPos = -1;
    for (int i = 9; i >= 0; i--) {
        if (canZero[a[i].second - 'A']) {
            zeroPos = i;
            break;
        }
    }

    int key[10];
    key[a[zeroPos].second - 'A'] = 0;
    int dig = 9;
    for (int i = 0; i < 10; i++) {
        if (i == zeroPos) continue;
        key[a[i].second - 'A'] = dig--;
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        long long tmp = 0;
        for (char c : s[i])
            tmp = tmp * 10 + key[c - 'A'];
        ans += tmp;
    }

    cout << ans;
}
