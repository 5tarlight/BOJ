#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

string s;
int n, k;

int parent[50];

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        parent[x] = y;
    }
}

int main() {
    fio();

    cin >> s >> k;
    n = s.size();
    for (int i = 0; i < n; i++)
        parent[i] = i;
    for (int i = 0; i < k; i++) {
        unite(i, n - k + i);
    }

    int ans = 0;
    map<int, vector<char>> cnt;
    for (int i = 0; i < n; i++) {
        cnt[find(i)].push_back(s[i]);
    }

    for (auto& [_, v] : cnt) {
        int c[26] = {0};
        for (char ch : v)
            c[ch - 'a']++;

        int mx = 0;
        for (int i = 0; i < 26; i++)
            mx = max(mx, c[i]);

        ans += v.size() - mx;
    }

    cout << ans;
}
