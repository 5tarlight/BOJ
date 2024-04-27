#include <iostream>
#include <algorithm>

using namespace std;

#define x first
#define y second

int distance(pair<int, int> a, pair<int, int> b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        pair<int, int> points[4];
        for (int i = 0; i < 4; i++) {
            cin >> points[i].x >> points[i].y;
        }

        int dist[6];
        int idx = 0;
        for (int i = 0; i < 4; i++)
            for (int j = i + 1; j < 4; j++)
                dist[idx++] = distance(points[i], points[j]);

        sort(dist, dist + 6);

        if (dist[0] == dist[1] && dist[1] == dist[2] && dist[2] == dist[3] && dist[4] == dist[5]) {
            cout << "1\n";
        } else {
            cout << "0\n";
        }
    }
}
