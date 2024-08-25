#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int tree[500001];
vector<pair<int, int>> a;
int n;

int sum(int i) {
    int ans = 0;

    while (i) {
        ans += tree[i];
        i -= (i & -i);
    }

    return ans;
}

void update(int i, int x) {
    while (i <= n) {
        tree[i] += x;
        i += (i & -i);
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back({ x, i + 1});
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++) {
        a[i].first = i + 1;
        swap(a[i].first, a[i].second);
    }

    sort(a.begin(), a.end());
    memset(tree, 0, sizeof(tree));

    for (int i = 0; i < n; i++) {
        int x = a[i].second;

        cout << (i + 1) - sum(x - 1) << '\n';
        update(x, 1);
    }
}
