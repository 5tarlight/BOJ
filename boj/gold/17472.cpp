#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int graph[10][10];
int island[10][10];
bool visited[10][10];
int n, m;
int cnt;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int parents[7];

void markNear(int a, int b) {
    queue<pair<int, int>> q;
    q.push({ a, b });
    cnt++;
    island[a][b] = cnt;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny] || graph[nx][ny] == 0)
                continue;

            island[nx][ny] = cnt;
            visited[nx][ny] = true;
            q.push({ nx, ny });
        }
    }
}

int find(int x) {
    if (parents[x] == x)
        return x;
    else
        return parents[x] = find(parents[x]);
}

void unite(int a, int b) {
    int pa = find(a);
    int pb = find(b);

    if (pa != pb)
        parents[pb] = pa;
}

struct Cmp {
    bool operator()(pair<int, pair<int, int>> &p1, pair<int, pair<int, int>> &p2) {
        return p1.first > p2.first;
    }
};

priority_queue<
        pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        Cmp
> pq;

void go(int x, int y) {
    int cur = island[x][y];

    for (int i = 0; i < 4; i++) {
        int ddx = dx[i];
        int ddy = dy[i];

        for (int j = 1;; j++) {
            int nx = x + ddx * j;
            int ny = y + ddy * j;

            if (
                    nx < 0 || nx >= n || ny < 0 || ny >= m ||
                    island[nx][ny] == cur
            )
                break;
            if (island[nx][ny] == 0)
                continue;
            if (j == 2 || j == 1)
                break;

            int target = island[nx][ny];
            pq.push({ j - 1, { cur, target }});
            break;
        }
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> graph[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!visited[i][j] && graph[i][j] == 1)
                markNear(i, j);

    for (int i = 1; i <= cnt; i++)
        parents[i] = i;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (graph[i][j] == 1)
                go(i, j);

    int cost = 0;
    while (!pq.empty()) {
        auto [c, p] = pq.top();
        auto [a, b] = p;
        pq.pop();

        if (find(a) == find(b))
            continue;
        unite(a, b);
        cost += c;
    }

    bool ok = true;
    for (int i = 1; i < cnt; i++) {
        for (int j = i + 1; j <= cnt; j++) {
            if (find(i) != find(j)) {
                ok = false;
                break;
            }
        }
        if (!ok)
            break;
    }

    if (ok)
        cout << cost;
    else
        cout << -1;
}
