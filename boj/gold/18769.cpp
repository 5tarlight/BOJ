#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int r, c;
int parents[500][500];

int find(int x, int y) {
    if (parents[x][y] == x * c + y) {
        return x * c + y;
    }
    return parents[x][y] = find(parents[x][y] / c, parents[x][y] % c);
}

void merge(int x1, int y1, int x2, int y2) {
    int p1 = find(x1, y1);
    int p2 = find(x2, y2);
    if (p1 == p2) {
        return;
    }
    parents[p1 / c][p1 % c] = p2;
}

void reset() {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            parents[i][j] = i * c + j;
        }
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        cin >> r >> c;
        reset();
        vector<pair<int, pair<int, int>>> edges;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c - 1; j++) {
                int w;
                cin >> w;
                edges.push_back({w, {i * c + j, i * c + j + 1}});
            }
        }

        for (int i = 0; i < r - 1; i++) {
            for (int j = 0; j < c; j++) {
                int w;
                cin >> w;
                edges.push_back({w, {i * c + j, (i + 1) * c + j}});
            }
        }

        sort(edges.begin(), edges.end());

        int ans = 0;
        for (auto edge : edges) {
            int w = edge.first;
            int x = edge.second.first / c;
            int y = edge.second.first % c;
            int nx = edge.second.second / c;
            int ny = edge.second.second % c;
            if (find(x, y) != find(nx, ny)) {
                merge(x, y, nx, ny);
                ans += w;
            }
        }

        cout << ans << '\n';
    }
}
