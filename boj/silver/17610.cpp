#include <iostream>
#include <vector>

using namespace std;

vector<bool> visited;
int n;
int a[200000];
int s;

void dfs(int i, int w) {
    if (i == n) {
        if (w > 0)
            visited[w] = true;
        return;
    }

    dfs(i + 1, w);
    dfs(i + 1, w - a[i]);
    dfs(i + 1, w + a[i]);
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];
    }

    visited.resize(s + 1, false);

    dfs(0, 0);

    int ans = 0;
    for (int i = 1; i <= s; i++) {
        if (!visited[i])
            ans++;
    }

    cout << ans << endl;
}
