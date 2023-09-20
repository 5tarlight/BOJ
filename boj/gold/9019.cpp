#include <iostream>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

string bfs(int start, int end) {
    queue<pair<int, string>> q;
    bool visited[10000];
    memset(visited, false, sizeof(visited));
    q.emplace(start, "");
    visited[start] = true;

    while (!q.empty()) {
        int x = q.front().first;
        string s = q.front().second;
        q.pop();

        if (x == end)
            return s;

        int dx = x * 2 % 10000;
        int sx = x == 0 ? 9999 : x - 1;
        int lx = x / 1000 + x % 1000 * 10;
        int rx = x % 10 * 1000 + x / 10;

        if (!visited[dx]) {
            visited[dx] = true;
            q.emplace(dx, s + "D");
        }
        if (!visited[sx]) {
            visited[sx] = true;
            q.emplace(sx, s + "S");
        }
        if (!visited[lx]) {
            visited[lx] = true;
            q.emplace(lx, s + "L");
        }
        if (!visited[rx]) {
            visited[rx] = true;
            q.emplace(rx, s + "R");
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++) {
        int a, b;
        cin >> a >> b;

        cout << bfs(a, b) << '\n';
    }
}
