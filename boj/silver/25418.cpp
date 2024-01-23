#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int a, k;
    cin >> a >> k;
    int size = k - a + 1;
    int visited[size];
    fill(visited, visited + size, 0);
    queue<int> q;

    visited[0] = 1;
    q.push(0);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i : { cur + 1, 2 * (cur + a) - a }) {
            if (i > size - 1 || visited[i] != 0)
                continue;

            if (a + i == k) {
                cout << visited[cur];
                return 0;
            }

            visited[i] = visited[cur] + 1;
            q.push(i);
        }
    }
}
