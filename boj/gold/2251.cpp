#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

bool graph[201][201][201];
bool found[201];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int a, b, c;
    cin >> a >> b >> c;
    graph[0][0][c] = true;

    queue<pair<int, pair<int, int>>> q;
    q.push({0, {0, c}});

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second.first;
        int z = q.front().second.second;
        q.pop();

        if (x != 0) {
            if (y < b) {
                int amount = min(x, b - y);
                if (!graph[x - amount][y + amount][z]) {
                    graph[x - amount][y + amount][z] = true;
                    q.push({x - amount, {y + amount, z}});
                }
            }

            if (z < c) {
                int amount = min(x, c - z);
                if (!graph[x - amount][y][z + amount]) {
                    graph[x - amount][y][z + amount] = true;
                    q.push({x - amount, {y, z + amount}});
                }
            }
        }

        if (y != 0) {
            if (x < a) {
                int amount = min(y, a - x);
                if (!graph[x + amount][y - amount][z]) {
                    graph[x + amount][y - amount][z] = true;
                    q.push({x + amount, {y - amount, z}});
                }
            }

            if (z < c) {
                int amount = min(y, c - z);
                if (!graph[x][y - amount][z + amount]) {
                    graph[x][y - amount][z + amount] = true;
                    q.push({x, {y - amount, z + amount}});
                }
            }
        }

        if (z != 0) {
            if (x < a) {
                int amount = min(z, a - x);
                if (!graph[x + amount][y][z - amount]) {
                    graph[x + amount][y][z - amount] = true;
                    q.push({x + amount, {y, z - amount}});
                }
            }

            if (y < b) {
                int amount = min(z, b - y);
                if (!graph[x][y + amount][z - amount]) {
                    graph[x][y + amount][z - amount] = true;
                    q.push({x, {y + amount, z - amount}});
                }
            }
        }
    }

    vector<int> ans;

    int sum = c;
    for (int j = 0; j <= b; j++) {
        if (graph[0][j][sum - j] && !found[sum - j]) {
            ans.push_back(sum - j);
            found[sum - j] = true;
        }
    }

    sort(ans.begin(), ans.end());

    for (int an : ans) {
        cout << an << ' ';
    }
}
