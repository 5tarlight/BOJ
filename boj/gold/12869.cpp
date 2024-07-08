#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int graph[61][61][61];
int da[] = { 9, 9, 3, 3, 1, 1 };
int db[] = { 3, 1, 9, 1, 9, 3 };
int dc[] = { 1, 3, 1, 9, 3, 9 };

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int a[] = { 0, 0, 0 };
    for (int i = 0; i < n; i++)
        cin >> a[i];

    queue<pair<int, pair<int, int>>> q;
    q.push({ a[0], { a[1], a[2] }});

    while (!q.empty()) {
        auto [ a, p ] = q.front();
        auto [ b, c ] = p;
        q.pop();

        for (int i = 0; i < 6; i++) {
            int na = max(0, a - da[i]);
            int nb = max(0, b - db[i]);
            int nc = max(0, c - dc[i]);

            if (graph[na][nb][nc] != 0)
                continue;

            if (na == 0 && nb == 0 && nc == 0) {
                cout << graph[a][b][c] + 1;
                return 0;
            }

            graph[na][nb][nc] = graph[a][b][c] + 1;
            q.push({ na, { nb, nc }});
        }
    }
}
