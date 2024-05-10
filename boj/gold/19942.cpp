#include <iostream>
#include <vector>

using namespace std;

int n;
int mp, mf, ms, mv;
int a[15][5];
bool visited[15];
vector<int> ansv;
int ans = 1e9;

void backtrack(int idx, int p, int f, int s, int v, int c) {
    if (p >= mp && f >= mf && s >= ms && v >= mv) {
        if (c < ans) {
            ans = c;

            ansv.clear();
            for (int i = 0; i < n; i++)
                if (visited[i])
                    ansv.push_back(i + 1);
        }

        return;
    } else if (idx == n)
        return;

    visited[idx] = true;
    backtrack(idx + 1, p + a[idx][0], f + a[idx][1], s + a[idx][2], v + a[idx][3], c + a[idx][4]);
    visited[idx] = false;
    backtrack(idx + 1, p, f, s, v, c);
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    cin >> mp >> mf >> ms >> mv;
    for (int i = 0; i < n; i++)
        cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3] >> a[i][4];

    backtrack(0, 0, 0, 0, 0, 0);

    if (ans == 1e9) {
        cout << -1;
        return 0;
    }

    cout << ans << '\n';
    for (int v : ansv)
        cout << v << ' ';
}
