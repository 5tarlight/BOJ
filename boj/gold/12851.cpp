#include <iostream>
#include <queue>
#include <cstring>

#define SIZE 100'001

using namespace std;

int graph[SIZE];

void bfs(int n, int k) {
    queue<int> q;
    q.push(n);
    graph[n] = 1;
    int minTime = 1e9;
    int next;
    int cnt = 0;

    if (n == k) {
        cout << "0\n1";
        return;
    }

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        if (minTime < graph[now])
            break;

        for (int i = 0; i < 3; i++) {
            if (i == 0)
                next = now - 1;
            else if (i == 1)
                next = now + 1;
            else
                next = now * 2;

            if (next < 0 || next > SIZE - 1)
                continue;

            if (next == k) {
                minTime = graph[now];
                cnt++;
            }

            if (graph[next] == 0 || graph[next] == graph[now] + 1) {
                q.push(next);
                graph[next] = graph[now] + 1;
            }
        }
    }

    cout << graph[k] - 1 << '\n';
    cout << cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    bfs(n, k);
}
