#include <iostream>

using namespace std;

int parents[3000];
pair<int, int> loc[3000];
int range[3000];

void init(int n) {
    for (int i = 0; i < n; i++)
        parents[i] = i;
}

int find(int x) {
    if (parents[x] == x)
        return x;
    else
        return parents[x] = find(parents[x]);
}

void uni(int x, int y) {
    int px = find(x);
    int py = find(y);
    if (px == py) return;

    parents[px] = py;
}

bool isConnected(int i, int j) {
    auto l1 = loc[i];
    auto l2 = loc[j];
    int dx = l1.first - l2.first;
    int dy = l1.second - l2.second;
    int dist = dx * dx + dy * dy;
    int r = range[i] + range[j];

    return dist <= r * r;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        init(n);
        for (int i = 0; i < n; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            loc[i] = { a, b };
            range[i] = c;
        }

        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
                if (isConnected(i, j))
                    uni(i, j);

        bool visited[3000] = { false, };
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int p = find(i);
            if (!visited[p]) {
                ans++;
                visited[p] = true;
            }
        }

        cout << ans << '\n';
    }
}
