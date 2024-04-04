#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int parents[1001];

int findParent(int x) {
    if (parents[x] == x) {
        return x;
    }
    return parents[x] = findParent(parents[x]);
}

void unionParent(int a, int b) {
    a = findParent(a);
    b = findParent(b);

    if (a < b) {
        parents[b] = a;
    } else {
        parents[a] = b;
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int num;
            cin >> num;

            if (i < j) {
                edges.push_back({num, {i, j}});
            }
        }
    }

    sort(edges.begin(), edges.end());
    for (int i = 1; i <= n; i++)
        parents[i] = i;

    long long ans = 0;
    for (auto edge : edges) {
        int cost = edge.first;
        int a = edge.second.first;
        int b = edge.second.second;

        if (findParent(a) != findParent(b)) {
            unionParent(a, b);
            ans += cost;
        }
    }

    cout << ans;
}
