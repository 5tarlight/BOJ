#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

using pii = pair<int, int>;

void sort3(int &a, int &b, int &c) {
    if (a > b) swap(a, b);
    if (b > c) swap(b, c);
    if (a > b) swap(a, b);
}

int main() {
    fio();

    int t;
    cin >> t;
    vector<array<int, 3>> qs(t);
    int maxv = 0;

    for (int i = 0; i < t; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        int tmp[3] = {a, b, c};
        sort(tmp, tmp + 3);
        qs[i] = {tmp[0], tmp[1], tmp[2]};
        maxv = max(maxv, tmp[2]);
    }

    vector dp(maxv + 1,
              vector(maxv + 1,
                     vector<pii>(maxv + 1, {1e9, 0})
              )
    );

    for (int w = 1; w <= maxv; w++) {
        for (int l = w; l <= maxv; l++) {
            for (int h = l; h <= maxv; h++) {
                if (w == l && l == h) {
                    dp[w][l][h] = {0, 1};
                } else {
                    int cut = 1e9, cnt = 0;
                    for (int x = 1; x <= w / 2; x++) {
                        auto &a = dp[x][l][h];
                        auto &b = dp[w - x][l][h];
                        int c = a.first + b.first + 1;
                        int d = a.second + b.second;
                        if (c < cut || (c == cut && d > cnt)) {
                            cut = c;
                            cnt = d;
                        }
                    }
                    for (int x = 1; x <= l / 2; x++) {
                        int a1 = min(w, x), b1 = max(w, x), c1 = h;
                        auto &a = dp[a1][b1][c1];
                        int a2 = min(w, l - x), b2 = max(w, l - x), c2 = h;
                        auto &b = dp[a2][b2][c2];
                        int c = a.first + b.first + 1;
                        int d = a.second + b.second;
                        if (c < cut || (c == cut && d > cnt)) {
                            cut = c;
                            cnt = d;
                        }
                    }
                    for (int x = 1; x <= h / 2; x++) {
                        int a1 = w, b1 = l, c1 = x;
                        sort3(a1, b1, c1);
                        auto &a = dp[a1][b1][c1];
                        int a2 = w, b2 = l, c2 = h - x;
                        sort3(a2, b2, c2);
                        auto &b = dp[a2][b2][c2];
                        int c = a.first + b.first + 1;
                        int d = a.second + b.second;
                        if (c < cut || (c == cut && d > cnt)) {
                            cut = c;
                            cnt = d;
                        }
                    }
                    dp[w][l][h] = {cut, cnt};
                }
            }
        }
    }

    for (auto [w, l, h] : qs) {
        cout << dp[w][l][h].second << "\n";
    }
}
