#include <iostream>
#include <algorithm>

using namespace std;

int n;
char graph[50][51];
int ans = 0;

int cntEdible() {
    int ret = 0;

    for (int i = 0; i < n; i++) {
        int cnt = 1;
        for (int j = 1; j < n; j++) {
            if (graph[i][j] == graph[i][j - 1]) {
                cnt++;
            } else {
                ret = max(ret, cnt);
                cnt = 1;
            }
        }
        ret = max(ret, cnt);
    }

    for (int i = 0; i < n; i++) {
        int cnt = 1;
        for (int j = 1; j < n; j++) {
            if (graph[j][i] == graph[j - 1][i]) {
                cnt++;
            } else {
                ret = max(ret, cnt);
                cnt = 1;
            }
        }
        ret = max(ret, cnt);
    }

    return ret;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> graph[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j + 1 < n) {
                if (graph[i][j] == graph[i][j + 1]) continue;

                swap(graph[i][j], graph[i][j + 1]);
                ans = max(cntEdible(), ans);
                swap(graph[i][j], graph[i][j + 1]);
            }

            if (i + 1 < n) {
                if (graph[i][j] == graph[i + 1][j]) continue;

                swap(graph[i][j], graph[i + 1][j]);
                ans = max(ans, cntEdible());
                swap(graph[i][j], graph[i + 1][j]);
            }
        }
    }

    cout << ans;
}
