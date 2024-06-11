#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
char type[123457];
int cnt[123457];
vector<int> child[123457];

long long dfs(int n) {
    if (child[n].empty()) {
        if (type[n] == 'W')
            return 0;
        else
            return cnt[n];
    }

    long long ans = 0;
    for (int c : child[n])
        ans += dfs(c);

    if (type[n] == 'W')
        return max(ans - cnt[n], 0LL);
    else
        return ans + cnt[n];
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 2; i <= n; i++) {
        int parent;
        cin >> type[i] >> cnt[i] >> parent;
        child[parent].push_back(i);
    }

    cout << dfs(1);
}
