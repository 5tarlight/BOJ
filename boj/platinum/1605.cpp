#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

constexpr int MAXN = 200000 + 5;
constexpr int BASE = 29;
constexpr int MOD = 10007;

string s;
int n;
int powBase[MAXN];
vector<int> table[MOD];

void clearTable() {
    for (int i = 0; i < MOD; i++) table[i].clear();
}

bool matchSub(int a, int b, int len) {
    for (int i = 0; i < len; i++)
        if (s[a + i] != s[b + i]) return false;
    return true;
}

bool existDup(int len) {
    if (len == 0) return true;

    clearTable();

    int h = 0;
    for (int i = 0; i < len; i++)
        h = (h * BASE + (s[i] - 'a')) % MOD;

    table[h].push_back(0);

    for (int i = len; i < n; i++) {
        h = (h - (long long)(s[i - len] - 'a') * powBase[len - 1] % MOD + MOD) % MOD;
        h = (h * BASE + (s[i] - 'a')) % MOD;

        int start = i - len + 1;

        for (int idx : table[h])
            if (matchSub(idx, start, len)) return true;

        table[h].push_back(start);
    }
    return false;
}

int main() {
    fio();

    cin >> n >> s;

    powBase[0] = 1;
    for (int i = 1; i < MAXN; i++)
        powBase[i] = (long long)powBase[i - 1] * BASE % MOD;

    int lo = 0, hi = n;
    while (lo < hi) {
        int mid = (lo + hi + 1) >> 1;
        if (existDup(mid)) lo = mid;
        else hi = mid - 1;
    }

    cout << lo;
}