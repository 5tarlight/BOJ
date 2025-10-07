#include <bits/stdc++.h>
using namespace std;

void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int main() {
    fio();

    vector<deque<int>> q(4, deque<int>(8));
    for (int i = 0; i < 4; i++) {
        string s; cin >> s;
        for (int j = 0; j < 8; j++)
            q[i][j] = s[j] - '0';
    }

    int k; cin >> k;
    while (k--) {
        int n, d;
        cin >> n >> d;
        n--;

        vector<int> dir(4, 0);
        dir[n] = d;

        for (int i = n; i < 3; i++) {
            if (q[i][2] != q[i + 1][6]) dir[i + 1] = -dir[i];
            else break;
        }

        for (int i = n; i > 0; i--) {
            if (q[i][6] != q[i - 1][2]) dir[i - 1] = -dir[i];
            else break;
        }

        // 회전
        for (int i = 0; i < 4; i++) {
            if (dir[i] == 1) {
                int tmp = q[i].back();
                q[i].pop_back();
                q[i].push_front(tmp);
            } else if (dir[i] == -1) {
                int tmp = q[i].front();
                q[i].pop_front();
                q[i].push_back(tmp);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < 4; i++) {
        if (q[i][0] == 1) ans += (1 << i);
    }

    cout << ans;
}
