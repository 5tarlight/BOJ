#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

bool isPrime[2001];
int n;
vector<int> a, b;
vector<vector<int>> adj;
vector<int> am, bm, visited;

void sieve() {
    memset(isPrime, true, sizeof isPrime);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= 2000; i++)
        if (isPrime[i])
            for (int j = i * i; j <= 2000; j += i)
                isPrime[j] = false;
}

bool dfs(int idx) {
    if (idx == 0 || visited[idx])
        return false;
    visited[idx] = true;

    for (int i = 0; i < adj[idx].size(); i++) {
        int nxt = adj[idx][i];
        if (bm[nxt] == -1 || dfs(bm[nxt])) {
            am[idx] = nxt;
            bm[nxt] = idx;
            return true;
        }
    }

    return false;
}

int main() {
    fio();

    sieve();
    cin >> n;

    int x; cin >> x;
    a.push_back(x);

    for (int i = 1; i < n; i++) {
        int tmp; cin >> tmp;

        if (x & 1) {
            if (tmp & 1) a.push_back(tmp);
            else b.push_back(tmp);
        } else {
            if (tmp & 1) b.push_back(tmp);
            else a.push_back(tmp);
        }
    }

    if (b.size() != a.size()) {
        cout << -1;
        return 0;
    }

    adj = vector<vector<int>>(a.size());
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < b.size(); j++)
            if (isPrime[a[i] + b[j]])
                adj[i].push_back(j);

    vector<int> ans;
    for (int i = 0; i < adj[0].size(); i++) {
        int bidx = adj[0][i];
        int sz = 1;

        am = vector<int>(a.size(), -1);
        bm = vector<int>(b.size(), -1);

        am[0] = bidx;
        bm[bidx] = 0;

        for (int j = 1; j < a.size(); j++) {
            visited = vector<int>(a.size(), false);
            if (dfs(j)) sz++;
        }

        if (sz == b.size())
            ans.push_back(b[bidx]);
    }

    if (ans.empty()) cout << -1;
    else {
        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << ' ';
    }
}
