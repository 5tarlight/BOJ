#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }
template <class OStream, class T> OStream &operator<<(OStream &os, const std::vector<T> &vec) { os << '['; for (auto v : vec) os << v << ','; os << ']'; return os; }
template <class OStream, class T, class U> OStream &operator<<(OStream &os, const std::pair<T, U> &pa) { return os << '(' << pa.first << ',' << pa.second << ')'; }
#ifdef YEAHx4
#define dbg(x) std::cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl
#else
#define dbg(x) ((void)0)
#endif

int n, m, a, b, c;
vector<pair<int, int>> adj[100001];

int dijkstra(int cc) {
    int dist[n + 1];
    fill(dist, dist + n + 1, INT_MAX);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[a] = 0;
    pq.push({ 0, a });

    while (!pq.empty()) {
        auto [cost, cur] = pq.top();
        pq.pop();

        if (cost > dist[cur]) continue;
        for (auto [nxt, nxtCost] : adj[cur]) {
            if (nxtCost > cc) continue;
            if (dist[cur] + nxtCost < dist[nxt]) {
                dist[nxt] = dist[cur] + nxtCost;
                pq.push({ dist[nxt], nxt });
            }
        }
    }

    return dist[b];
}

int main() {
    fio();

    cin >> n >> m >> a >> b >> c;
    while (m--) {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({ y, w });
        adj[y].push_back({ x, w });
    }

    int ans = 1e9;
    int l = 1, r = 20;
    while (l <= r) {
        int mid = (l + r) / 2;
        int dist = dijkstra(mid);

        if (dist <= c) {
            ans = min(ans, mid);
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    if (ans == 1e9) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}
