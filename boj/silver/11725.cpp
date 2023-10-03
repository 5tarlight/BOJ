#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> tree[100'0001];
int p[100'0001];

void dfs(int cur) {
    for (int nxt : tree[cur]) {
        if (p[cur] == nxt)
            continue;
        p[nxt] = cur;

        dfs(nxt);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(1);

    for (int i = 2; i <= n; i++)
        cout << p[i] << '\n';
}
