#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int n, cnt = 0;
int a[100001];
bool vis[100001];
bool fin[100001];

void dfs(int x) {
    vis[x] = true;

    if (!vis[a[x]])
        dfs(a[x]);
    else if (!fin[a[x]]) {
        for (int i = a[x]; i != x; i = a[i])
            cnt++;
        cnt++;
    }

    fin[x] = true;
}

int main() {
    fio();

    int t; cin >> t;
    while (t--) {
        cnt = 0;
        cin >> n;

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            vis[i] = false;
            fin[i] = false;
        }

        for (int i = 1; i <= n; i++)
            if (!vis[i])
                dfs(i);

        cout << n - cnt << '\n';
    }
}
