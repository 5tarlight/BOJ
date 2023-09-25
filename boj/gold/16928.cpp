#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> ladders[100];
    vector<int> snakes[100];
    int map[100];
    queue<int> q;
    bool visited[100];

    memset(map, 0, sizeof(map));
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        ladders[a - 1].push_back(b - 1);
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        snakes[a - 1].push_back(b - 1);
    }

    q.push(0);
    visited[0] = true;
    while (!q.empty()) {
        int s = q.front();
        q.pop();

        for (int i = 1; i <= 6; i++) {
            int x = s + i;
            if (x >= 100)
                continue;

            if (!visited[x]) {
                map[x] = map[s] + 1;
                visited[x] = true;

                if (!ladders[x].empty()) {
                    int l = ladders[x][0];
                    if (!visited[l]) {
                        map[l] = map[s] + 1;
                        q.push(l);
                        visited[l] = true;
                    }
                } else if (!snakes[x].empty()) {
                    int l = snakes[x][0];
                    if (!visited[l]) {
                        map[l] = map[s] + 1;
                        q.push(l);
                        visited[l] = true;
                    }
                } else {
                    q.push(x);
                }
            }
        }
    }

    cout << map[99];
}
