#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vpii;

vpii x, y, z;
vector<pair<int, pii>> dist;
int parents[100001];

int find(int x) {
    if (parents[x] == x) return x;
    else return parents[x] = find(parents[x]);
}

void unite(int a, int b) {
    int pa = find(a);
    int pb = find(b);

    if (pa != pb)
        parents[pa] = pb;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        parents[i] = i;
        int a, b, c;
        cin >> a >> b >> c;
        x.push_back({ a, i });
        y.push_back({ b, i });
        z.push_back({ c, i });
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    sort(z.begin(), z.end());

    for (int i = 0; i < n - 1; i++) {
        dist.push_back({ x[i + 1].first - x[i].first, {x[i].second, x[i + 1].second }});
        dist.push_back({ y[i + 1].first - y[i].first, {y[i].second, y[i + 1].second }});
        dist.push_back({ z[i + 1].first - z[i].first, {z[i].second, z[i + 1].second }});
    }

    sort(dist.begin(), dist.end());

    int ans = 0;
    for (int i = 0; i < dist.size(); i++) {
        auto [d, p] = dist[i];
        auto [a, b] = p;

        if (find(a) != find(b)) {
            unite(a, b);
            ans += d;
        }
    }

    cout << ans;
}
